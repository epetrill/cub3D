/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:45:26 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 21:08:44 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	tex_calculation(t_mapinfo *map)
{
	if (map->ray.side == 0)
		map->ray.wall_x = map->player.pos_y + map->ray.perpwalldist *
		map->ray.raydir_y;
	else
		map->ray.wall_x = map->player.pos_x + map->ray.perpwalldist *
		map->ray.raydir_x;
	map->ray.wall_x -= floor(map->ray.wall_x);
	map->ray.tex_x = (int)(map->ray.wall_x * (double)WIDTH);
	if (map->ray.side == 0 && map->ray.raydir_x > 0)
		map->ray.tex_x = WIDTH - map->ray.tex_x - 1;
	if (map->ray.side == 1 && map->ray.raydir_y < 0)
		map->ray.tex_x = WIDTH - map->ray.tex_x - 1;
	map->ray.step = 1.0 * HEIGHT / map->ray.lineheight;
	map->ray.texpos = (map->ray.drawstart - map->res_y / 2 +
	map->ray.lineheight / 2) * map->ray.step;
}

void	wall_height_calculation(t_mapinfo *map)
{
	map->ray.lineheight = (int)(map->res_y / map->ray.perpwalldist);
	map->ray.drawstart = -map->ray.lineheight / 2 + map->res_y / 2;
	if (map->ray.drawstart < 0)
		map->ray.drawstart = 0;
	map->ray.drawend = map->ray.lineheight / 2 + map->res_y / 2;
	if (map->ray.drawend >= map->res_y)
		map->ray.drawend = map->res_y - 1;
}

void	wall_distance_calculation(t_mapinfo *map)
{
	if (map->ray.side == 0)
		map->ray.perpwalldist = (map->ray.map_x - map->player.pos_x +
		(1 - map->ray.step_x) / 2) / map->ray.raydir_x;
	else
		map->ray.perpwalldist = (map->ray.map_y - map->player.pos_y +
		(1 - map->ray.step_y) / 2) / map->ray.raydir_y;
}

void	hit_analyzing(t_mapinfo *map)
{
	while (map->ray.hit == 0)
	{
		if (map->ray.sidedist_x < map->ray.sidedist_y)
		{
			map->ray.sidedist_x += map->ray.deltadist_x;
			map->ray.map_x += map->ray.step_x;
			map->ray.side = 0;
		}
		else
		{
			map->ray.sidedist_y += map->ray.deltadist_y;
			map->ray.map_y += map->ray.step_y;
			map->ray.side = 1;
		}
		if (map->map[map->ray.map_y][map->ray.map_x] == '1')
			map->ray.hit = 1;
	}
}

void	step_calculation(t_mapinfo *map)
{
	if (map->ray.raydir_x < 0)
	{
		map->ray.step_x = -1;
		map->ray.sidedist_x = (map->player.pos_x - map->ray.map_x) *
		map->ray.deltadist_x;
	}
	else
	{
		map->ray.step_x = 1;
		map->ray.sidedist_x = (map->ray.map_x + 1.0 - map->player.pos_x) *
		map->ray.deltadist_x;
	}
	if (map->ray.raydir_y < 0)
	{
		map->ray.step_y = -1;
		map->ray.sidedist_y = (map->player.pos_y - map->ray.map_y) *
		map->ray.deltadist_y;
	}
	else
	{
		map->ray.step_y = 1;
		map->ray.sidedist_y = (map->ray.map_y + 1.0 - map->player.pos_y) *
		map->ray.deltadist_y;
	}
}
