/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 02:27:18 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 02:47:44 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	north_setter(t_mapinfo *pinfo)
{
	pinfo->player.dir_x = 0;
	pinfo->player.dir_y = -1;
	pinfo->player.plane_x = 0.66;
	pinfo->player.plane_y = 0.0;
}

void	west_setter(t_mapinfo *pinfo)
{
	pinfo->player.dir_x = -1;
	pinfo->player.dir_y = 0;
	pinfo->player.plane_x = 0.0;
	pinfo->player.plane_y = -0.66;
}

void	south_setter(t_mapinfo *pinfo)
{
	pinfo->player.dir_x = 0;
	pinfo->player.dir_y = 1;
	pinfo->player.plane_x = -0.66;
	pinfo->player.plane_y = 0.0;
}

void	east_setter(t_mapinfo *pinfo)
{
	pinfo->player.dir_x = 1;
	pinfo->player.dir_y = 0;
	pinfo->player.plane_x = 0.0;
	pinfo->player.plane_y = 0.66;
}

void	angle_setter(t_mapinfo *pinfo)
{
	if (pinfo->cardinal == 1)
		north_setter(pinfo);
	else if (pinfo->cardinal == 2)
		west_setter(pinfo);
	else if (pinfo->cardinal == 3)
		south_setter(pinfo);
	else if (pinfo->cardinal == 4)
		east_setter(pinfo);
	pinfo->player.movespeed = 0.05;
	pinfo->player.rotspeed = 0.05;
}