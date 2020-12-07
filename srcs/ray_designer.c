/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_designer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:19:05 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 20:52:40 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	texturing_buf(t_mapinfo *map, int x)
{
	int		y;
	int		color;

	y = map->ray.drawstart;
	while (y < map->ray.drawend)
	{
		map->ray.tex_y = (int)map->ray.texpos & (HEIGHT - 1);
		map->ray.texpos += map->ray.step;
		if (map->ray.side == 0 && map->ray.raydir_x > 0)
			color = map->tex[3][HEIGHT * map->ray.tex_y + map->ray.tex_x];
		else if (map->ray.side == 0 && map->ray.raydir_x < 0)
			color = map->tex[2][HEIGHT * map->ray.tex_y + map->ray.tex_x];
		else if (map->ray.side == 1 && map->ray.raydir_y < 0)
			color = map->tex[0][HEIGHT * map->ray.tex_y + map->ray.tex_x];
		else
			color = map->tex[1][HEIGHT * map->ray.tex_y + map->ray.tex_x];
		map->buffer[y][x] = color;
		y++;
	}
}

void	ray_init(t_mapinfo *map, int x)
{
	map->ray.camera_x = 2 * x / (double)map->res_x - 1;
	map->ray.raydir_x = map->player.dir_x + map->player.plane_x
	* map->ray.camera_x;
	map->ray.raydir_y = map->player.dir_y + map->player.plane_y
	* map->ray.camera_x;
	map->ray.map_x = (int)map->player.pos_x;
	map->ray.map_y = (int)map->player.pos_y;
	map->ray.deltadist_x = fabs(1 / map->ray.raydir_x);
	map->ray.deltadist_y = fabs(1 / map->ray.raydir_y);
	map->ray.hit = 0;
}

void	draw_floor_ceiling(t_mapinfo *map)
{
	int x;
	int y;

	y = 0;
	while (y < map->res_y)
	{
		x = 0;
		while (x < map->res_x)
		{
			if (y > map->res_y / 2)
				map->buffer[y][x] = map->hexfloor;
			else
				map->buffer[y][x] = map->hexceil;
			x++;
		}
		y++;
	}
}

void	designer(t_mapinfo *map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < map->res_y)
	{
		while (x < map->res_x)
		{
			map->data.img_data[y * map->res_x + x] = map->buffer[y][x];
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(map->data.ptr, map->data.win,
	map->data.img, 0, 0);
}

void	launcher(t_mapinfo *map)
{
	int x;

	x = 0;
	draw_floor_ceiling(map);
	while (x < map->res_x)
	{
		ray_init(map, x);
		step_calculation(map);
		hit_analyzing(map);
		wall_distance_calculation(map);
		wall_height_calculation(map);
		tex_calculation(map);
		texturing_buf(map, x);
		map->spribuf[x] = map->ray.perpwalldist;
		x++;
	}
}
