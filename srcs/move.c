/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 02:36:42 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 09:40:32 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void		tex_loader(t_mapinfo *pinfo)
{
    img_loader(pinfo, pinfo->tex[0], pinfo->north);
    img_loader(pinfo, pinfo->tex[1], pinfo->south);
    img_loader(pinfo, pinfo->tex[2], pinfo->west);
    img_loader(pinfo, pinfo->tex[3], pinfo->east);
    img_loader(pinfo, pinfo->tex[4], pinfo->path_sprites);
}

void		moving_up(t_mapinfo *pinfo)
{
	if (pinfo->map[(int)(pinfo->player.pos_y)][(int)(pinfo->player.pos_x +
	pinfo->player.dir_x * pinfo->player.movespeed)] != '1'
	&& pinfo->map[(int)(pinfo->player.pos_y)][(int)(pinfo->player.pos_x +
	pinfo->player.dir_x * pinfo->player.movespeed)] != '2')
		pinfo->player.pos_x += pinfo->player.dir_x * pinfo->player.movespeed;
	if (pinfo->map[(int)(pinfo->player.pos_y + pinfo->player.dir_y *
	pinfo->player.movespeed)][(int)(pinfo->player.pos_x)] != '1')
		pinfo->player.pos_y += pinfo->player.dir_y * pinfo->player.movespeed;
}

void		moving_down(t_mapinfo *pinfo)
{
	if (pinfo->map[(int)(pinfo->player.pos_y)][(int)(pinfo->player.pos_x -
	pinfo->player.dir_x * pinfo->player.movespeed)] != '1'
	&& pinfo->map[(int)(pinfo->player.pos_y)][(int)(pinfo->player.pos_x -
	pinfo->player.dir_x * pinfo->player.movespeed)] != '2')
		pinfo->player.pos_x -= pinfo->player.dir_x * pinfo->player.movespeed;
	if (pinfo->map[(int)(pinfo->player.pos_y - pinfo->player.dir_y *
	pinfo->player.movespeed)][(int)(pinfo->player.pos_x)] != '1')
		pinfo->player.pos_y -= pinfo->player.dir_y * pinfo->player.movespeed;
}

void		moving_left(t_mapinfo *pinfo)
{
	if (pinfo->map[(int)(pinfo->player.pos_y)][(int)(pinfo->player.pos_x -
	pinfo->player.plane_x * pinfo->player.movespeed)] != '1')
		pinfo->player.pos_x -= pinfo->player.plane_x * pinfo->player.movespeed;
	if (pinfo->map[(int)(pinfo->player.pos_y - pinfo->player.plane_y *
	pinfo->player.movespeed)][(int)(pinfo->player.pos_x)] != '1')
		pinfo->player.pos_y -= pinfo->player.plane_y * pinfo->player.movespeed;
}

void		moving_right(t_mapinfo *pinfo)
{
	if (pinfo->map[(int)(pinfo->player.pos_y)][(int)(pinfo->player.pos_x -
	pinfo->player.plane_x * pinfo->player.movespeed)] != '1')
		pinfo->player.pos_x += pinfo->player.plane_x * pinfo->player.movespeed;
	if (pinfo->map[(int)(pinfo->player.pos_y - pinfo->player.plane_y *
	pinfo->player.movespeed)][(int)(pinfo->player.pos_x)] != '1')
		pinfo->player.pos_y += pinfo->player.plane_y * pinfo->player.movespeed;
}