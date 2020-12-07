/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spriter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:59:30 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 10:05:51 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	get_sprite_color(t_mapinfo *pinfo, int stripe)
{
	int	color;
	int	y;
	int	draw;

	pinfo->s_ray.tex_x = (int)((256 * (stripe - (-pinfo->s_ray.width / 2 +
	pinfo->s_ray.screen_x)) * WIDTH / pinfo->s_ray.width) / 256);
	if (pinfo->s_ray.transform_y > 0 && stripe > 0 && stripe < pinfo->res_x &&
	pinfo->s_ray.transform_y < pinfo->spribuf[stripe])
	{
		y = pinfo->s_ray.draw_start_y;
		while (y < pinfo->s_ray.draw_end_y)
		{
			draw = (y - pinfo->s_ray.v_move_screen) * 256 - pinfo->res_y * 128 +
			pinfo->s_ray.height * 128;
			pinfo->s_ray.tex_y = ((draw * HEIGHT) / pinfo->s_ray.height) / 256;
			color = pinfo->tex[4][WIDTH * pinfo->s_ray.tex_y + pinfo->s_ray.tex_x];
			if ((color & 0x00FFFFFF) != 0)
				pinfo->buffer[y][stripe] = color;
			y++;
		}
	}
}

void	calculate_sprite_width(t_mapinfo *pinfo)
{
	int	u_div;

	u_div = 1;
	pinfo->s_ray.width = (int)fabs((pinfo->res_y / pinfo->s_ray.transform_y) / u_div);
	pinfo->s_ray.draw_start_x = -pinfo->s_ray.width / 2 + pinfo->s_ray.screen_x;
	if (pinfo->s_ray.draw_start_x < 0)
		pinfo->s_ray.draw_start_x = 0;
	pinfo->s_ray.draw_end_x = pinfo->s_ray.width / 2 + pinfo->s_ray.screen_x;
	if (pinfo->s_ray.draw_end_x >= pinfo->res_x)
		pinfo->s_ray.draw_end_x = pinfo->res_x - 1;
}

void	calculate_sprite_height(t_mapinfo *pinfo)
{
	int	div;

	div = 1;
	pinfo->s_ray.height = (int)fabs((pinfo->res_y / pinfo->s_ray.transform_y) / div);
	pinfo->s_ray.draw_start_y = -pinfo->s_ray.height / 2 + pinfo->res_y / 2 +
	pinfo->s_ray.v_move_screen;
	if (pinfo->s_ray.draw_start_y < 0)
		pinfo->s_ray.draw_start_y = 0;
	pinfo->s_ray.draw_end_y = pinfo->s_ray.height / 2 + pinfo->res_y / 2 +
	pinfo->s_ray.v_move_screen;
	if (pinfo->s_ray.draw_end_y >= pinfo->res_y)
		pinfo->s_ray.draw_end_y = pinfo->res_y - 1;
}

void	translating_sprite(t_mapinfo *pinfo, int i)
{
	double	mode;

	mode = 0.0;
	pinfo->s_ray.x = pinfo->sprite[i].x - pinfo->player.pos_x;
	pinfo->s_ray.y = pinfo->sprite[i].y - pinfo->player.pos_y;
	pinfo->s_ray.inversion = 1.0 / (pinfo->player.plane_x * pinfo->player.dir_y -
	pinfo->player.dir_x * pinfo->player.plane_y);
	pinfo->s_ray.transform_x = pinfo->s_ray.inversion *
	(pinfo->player.dir_y * pinfo->s_ray.x - pinfo->player.dir_x * pinfo->s_ray.y);
	pinfo->s_ray.transform_y = pinfo->s_ray.inversion * (-pinfo->player.plane_y *
	pinfo->s_ray.x + pinfo->player.plane_x * pinfo->s_ray.y);
	pinfo->s_ray.screen_x = (int)((pinfo->res_x / 2) *
	(1 + pinfo->s_ray.transform_x / pinfo->s_ray.transform_y));
	pinfo->s_ray.v_move_screen = (int)(mode / pinfo->s_ray.transform_y);
}

void	spriter(t_mapinfo *pinfo)
{
	int	i;
	int	stripe;

	i = 0;
	pinfo->numsprite = pinfo->counter_sprite;
	sprite_sorter(pinfo);
	while (i < pinfo->numsprite)
	{
		translating_sprite(pinfo, i);
		calculate_sprite_height(pinfo);
		calculate_sprite_width(pinfo);
		stripe = pinfo->s_ray.draw_start_x;
		while (stripe < pinfo->s_ray.draw_end_x)
		{
			get_sprite_color(pinfo, stripe);
			stripe++;
		}
		i++;
	}
}