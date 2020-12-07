/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spriter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:59:30 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 20:53:10 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	get_sprite_color(t_mapinfo *map, int stripe)
{
	int	color;
	int	y;
	int	draw;

	map->s_ray.tex_x = (int)((256 * (stripe - (-map->s_ray.width / 2 +
	map->s_ray.screen_x)) * WIDTH / map->s_ray.width) / 256);
	if (map->s_ray.transform_y > 0 && stripe > 0 && stripe < map->res_x &&
	map->s_ray.transform_y < map->spribuf[stripe])
	{
		y = map->s_ray.draw_start_y;
		while (y < map->s_ray.draw_end_y)
		{
			draw = (y - map->s_ray.v_move_screen) * 256 - map->res_y * 128 +
			map->s_ray.height * 128;
			map->s_ray.tex_y = ((draw * HEIGHT) / map->s_ray.height) / 256;
			color = map->tex[4][WIDTH * map->s_ray.tex_y + map->s_ray.tex_x];
			if ((color & 0x00FFFFFF) != 0)
				map->buffer[y][stripe] = color;
			y++;
		}
	}
}

void	calculate_sprite_width(t_mapinfo *map)
{
	int	u_div;

	u_div = 1;
	map->s_ray.width = (int)fabs((map->res_y / map->s_ray.transform_y) / u_div);
	map->s_ray.draw_start_x = -map->s_ray.width / 2 + map->s_ray.screen_x;
	if (map->s_ray.draw_start_x < 0)
		map->s_ray.draw_start_x = 0;
	map->s_ray.draw_end_x = map->s_ray.width / 2 + map->s_ray.screen_x;
	if (map->s_ray.draw_end_x >= map->res_x)
		map->s_ray.draw_end_x = map->res_x - 1;
}

void	calculate_sprite_height(t_mapinfo *map)
{
	int	div;

	div = 1;
	map->s_ray.height = (int)fabs((map->res_y / map->s_ray.transform_y) / div);
	map->s_ray.draw_start_y = -map->s_ray.height / 2 + map->res_y / 2 +
	map->s_ray.v_move_screen;
	if (map->s_ray.draw_start_y < 0)
		map->s_ray.draw_start_y = 0;
	map->s_ray.draw_end_y = map->s_ray.height / 2 + map->res_y / 2 +
	map->s_ray.v_move_screen;
	if (map->s_ray.draw_end_y >= map->res_y)
		map->s_ray.draw_end_y = map->res_y - 1;
}

void	translating_sprite(t_mapinfo *map, int i)
{
	double	mode;

	mode = 0.0;
	map->s_ray.x = map->sprite[i].x - map->player.pos_x;
	map->s_ray.y = map->sprite[i].y - map->player.pos_y;
	map->s_ray.inversion = 1.0 / (map->player.plane_x * map->player.dir_y -
	map->player.dir_x * map->player.plane_y);
	map->s_ray.transform_x = map->s_ray.inversion *
	(map->player.dir_y * map->s_ray.x - map->player.dir_x * map->s_ray.y);
	map->s_ray.transform_y = map->s_ray.inversion * (-map->player.plane_y *
	map->s_ray.x + map->player.plane_x * map->s_ray.y);
	map->s_ray.screen_x = (int)((map->res_x / 2) *
	(1 + map->s_ray.transform_x / map->s_ray.transform_y));
	map->s_ray.v_move_screen = (int)(mode / map->s_ray.transform_y);
}

void	spriter(t_mapinfo *map)
{
	int	i;
	int	stripe;

	i = 0;
	map->numsprite = map->counter_sprite;
	sprite_sorter(map);
	while (i < map->numsprite)
	{
		translating_sprite(map, i);
		calculate_sprite_height(map);
		calculate_sprite_width(map);
		stripe = map->s_ray.draw_start_x;
		while (stripe < map->s_ray.draw_end_x)
		{
			get_sprite_color(map, stripe);
			stripe++;
		}
		i++;
	}
}
