/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 02:36:42 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 20:56:18 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void		tex_loader(t_mapinfo *map)
{
	img_loader(map, map->tex[0], map->north);
	img_loader(map, map->tex[1], map->south);
	img_loader(map, map->tex[2], map->west);
	img_loader(map, map->tex[3], map->east);
	img_loader(map, map->tex[4], map->path_sprites);
}

void		moving_up(t_mapinfo *map)
{
	if (map->map[(int)(map->player.pos_y)][(int)(map->player.pos_x +
	map->player.dir_x * map->player.movespeed)] != '1'
	&& map->map[(int)(map->player.pos_y)][(int)(map->player.pos_x +
	map->player.dir_x * map->player.movespeed)] != '2')
		map->player.pos_x += map->player.dir_x * map->player.movespeed;
	if (map->map[(int)(map->player.pos_y + map->player.dir_y *
	map->player.movespeed)][(int)(map->player.pos_x)] != '1')
		map->player.pos_y += map->player.dir_y * map->player.movespeed;
}

void		moving_down(t_mapinfo *map)
{
	if (map->map[(int)(map->player.pos_y)][(int)(map->player.pos_x -
	map->player.dir_x * map->player.movespeed)] != '1'
	&& map->map[(int)(map->player.pos_y)][(int)(map->player.pos_x -
	map->player.dir_x * map->player.movespeed)] != '2')
		map->player.pos_x -= map->player.dir_x * map->player.movespeed;
	if (map->map[(int)(map->player.pos_y - map->player.dir_y *
	map->player.movespeed)][(int)(map->player.pos_x)] != '1')
		map->player.pos_y -= map->player.dir_y * map->player.movespeed;
}

void		moving_left(t_mapinfo *map)
{
	if (map->map[(int)(map->player.pos_y)][(int)(map->player.pos_x -
	map->player.plane_x * map->player.movespeed)] != '1')
		map->player.pos_x -= map->player.plane_x * map->player.movespeed;
	if (map->map[(int)(map->player.pos_y - map->player.plane_y *
	map->player.movespeed)][(int)(map->player.pos_x)] != '1')
		map->player.pos_y -= map->player.plane_y * map->player.movespeed;
}

void		moving_right(t_mapinfo *map)
{
	if (map->map[(int)(map->player.pos_y)][(int)(map->player.pos_x -
	map->player.plane_x * map->player.movespeed)] != '1')
		map->player.pos_x += map->player.plane_x * map->player.movespeed;
	if (map->map[(int)(map->player.pos_y - map->player.plane_y *
	map->player.movespeed)][(int)(map->player.pos_x)] != '1')
		map->player.pos_y += map->player.plane_y * map->player.movespeed;
}
