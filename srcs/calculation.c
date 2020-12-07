/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:45:26 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 09:50:29 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	tex_calculation(t_mapinfo *pinfo)
{
	if (pinfo->ray.side == 0)
		pinfo->ray.wall_x = pinfo->player.pos_y + pinfo->ray.perpwalldist *
		pinfo->ray.raydir_y;
	else
		pinfo->ray.wall_x = pinfo->player.pos_x + pinfo->ray.perpwalldist *
		pinfo->ray.raydir_x;
	pinfo->ray.wall_x -= floor(pinfo->ray.wall_x);
	pinfo->ray.tex_x = (int)(pinfo->ray.wall_x * (double)WIDTH);
	if (pinfo->ray.side == 0 && pinfo->ray.raydir_x > 0)
		pinfo->ray.tex_x = WIDTH - pinfo->ray.tex_x - 1;
	if (pinfo->ray.side == 1 && pinfo->ray.raydir_y < 0)
		pinfo->ray.tex_x = WIDTH - pinfo->ray.tex_x - 1;
	pinfo->ray.step = 1.0 * HEIGHT / pinfo->ray.lineheight;
	pinfo->ray.texpos = (pinfo->ray.drawstart - pinfo->res_y / 2 +
	pinfo->ray.lineheight / 2) * pinfo->ray.step;
}

void	wall_height_calculation(t_mapinfo *pinfo)
{
	pinfo->ray.lineheight = (int)(pinfo->res_y / pinfo->ray.perpwalldist);
	pinfo->ray.drawstart = -pinfo->ray.lineheight / 2 + pinfo->res_y / 2;
	if (pinfo->ray.drawstart < 0)
		pinfo->ray.drawstart = 0;
	pinfo->ray.drawend = pinfo->ray.lineheight / 2 + pinfo->res_y / 2;
	if (pinfo->ray.drawend >= pinfo->res_y)
		pinfo->ray.drawend = pinfo->res_y - 1;
}

void	wall_distance_calculation(t_mapinfo *pinfo)
{
	if (pinfo->ray.side == 0)
		pinfo->ray.perpwalldist = (pinfo->ray.map_x - pinfo->player.pos_x +
		(1 - pinfo->ray.step_x) / 2) / pinfo->ray.raydir_x;
	else
		pinfo->ray.perpwalldist = (pinfo->ray.map_y - pinfo->player.pos_y +
		(1 - pinfo->ray.step_y) / 2) / pinfo->ray.raydir_y;
}

void	hit_analyzing(t_mapinfo *pinfo)
{
	while (pinfo->ray.hit == 0)
	{
		if (pinfo->ray.sidedist_x < pinfo->ray.sidedist_y)
		{
			pinfo->ray.sidedist_x += pinfo->ray.deltadist_x;
			pinfo->ray.map_x += pinfo->ray.step_x;
			pinfo->ray.side = 0;
		}
		else
		{
			pinfo->ray.sidedist_y += pinfo->ray.deltadist_y;
			pinfo->ray.map_y += pinfo->ray.step_y;
			pinfo->ray.side = 1;
		}
		if (pinfo->map[pinfo->ray.map_y][pinfo->ray.map_x] == '1')
			pinfo->ray.hit = 1;
	}
}

void	step_calculation(t_mapinfo *pinfo)
{
	if (pinfo->ray.raydir_x < 0)
	{
		pinfo->ray.step_x = -1;
		pinfo->ray.sidedist_x = (pinfo->player.pos_x - pinfo->ray.map_x) *
		pinfo->ray.deltadist_x;
	}
	else
	{
		pinfo->ray.step_x = 1;
		pinfo->ray.sidedist_x = (pinfo->ray.map_x + 1.0 - pinfo->player.pos_x) *
		pinfo->ray.deltadist_x;
	}
	if (pinfo->ray.raydir_y < 0)
	{
		pinfo->ray.step_y = -1;
		pinfo->ray.sidedist_y = (pinfo->player.pos_y - pinfo->ray.map_y) *
		pinfo->ray.deltadist_y;
	}
	else
	{
		pinfo->ray.step_y = 1;
		pinfo->ray.sidedist_y = (pinfo->ray.map_y + 1.0 - pinfo->player.pos_y) *
		pinfo->ray.deltadist_y;
	}
}