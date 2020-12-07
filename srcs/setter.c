/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 02:27:18 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 20:56:32 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	north_setter(t_mapinfo *map)
{
	map->player.dir_x = 0;
	map->player.dir_y = -1;
	map->player.plane_x = 0.66;
	map->player.plane_y = 0.0;
}

void	west_setter(t_mapinfo *map)
{
	map->player.dir_x = -1;
	map->player.dir_y = 0;
	map->player.plane_x = 0.0;
	map->player.plane_y = -0.66;
}

void	south_setter(t_mapinfo *map)
{
	map->player.dir_x = 0;
	map->player.dir_y = 1;
	map->player.plane_x = -0.66;
	map->player.plane_y = 0.0;
}

void	east_setter(t_mapinfo *map)
{
	map->player.dir_x = 1;
	map->player.dir_y = 0;
	map->player.plane_x = 0.0;
	map->player.plane_y = 0.66;
}

void	angle_setter(t_mapinfo *map)
{
	if (map->cardinal == 1)
		north_setter(map);
	else if (map->cardinal == 2)
		west_setter(map);
	else if (map->cardinal == 3)
		south_setter(map);
	else if (map->cardinal == 4)
		east_setter(map);
	map->player.movespeed = 0.05;
	map->player.rotspeed = 0.05;
}
