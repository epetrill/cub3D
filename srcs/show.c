/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 03:10:26 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 20:59:49 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		close_game(t_mapinfo *map)
{
	mlx_destroy_image(map->data.ptr, map->data.img);
	mlx_destroy_window(map->data.ptr, map->data.win);
	ft_freestruct(map);
	exit(1);
}

int		key_release(int code, t_mapinfo *map)
{
	if (code == KEY_UP || code == KEY_Z)
		moving_up(map);
	if (code == KEY_DOWN || code == KEY_S)
		moving_down(map);
	if (code == KEY_Q)
		moving_left(map);
	if (code == KEY_D)
		moving_right(map);
	if (code == KEY_LEFT)
		watching_left(map);
	if (code == KEY_RIGHT)
		watching_right(map);
	return (0);
}

int		key_press(int code, t_mapinfo *map, int choice)
{
	key_release(code, map);
	if (code == KEY_ESC)
	{
		if (choice != 118)
			ft_putstr("Vous avez quitte en appuyant sur echap !\n");
		ft_putstr("Fermeture du jeu !\n");
		return (close_game(map));
	}
	return (0);
}

void	watching_left(t_mapinfo *map)
{
	map->player.old_dir_x = map->player.dir_x;
	map->player.dir_x = map->player.dir_x * cos(-map->player.rotspeed) -
	map->player.dir_y * sin(-map->player.rotspeed);
	map->player.dir_y = map->player.old_dir_x * sin(-map->player.rotspeed) +
	map->player.dir_y * cos(-map->player.rotspeed);
	map->player.old_plane_x = map->player.plane_x;
	map->player.plane_x = map->player.plane_x * cos(-map->player.rotspeed) -
	map->player.plane_y * sin(-map->player.rotspeed);
	map->player.plane_y = map->player.old_plane_x *
	sin(-map->player.rotspeed) + map->player.plane_y *
	cos(-map->player.rotspeed);
}

void	watching_right(t_mapinfo *map)
{
	map->player.old_dir_x = map->player.dir_x;
	map->player.dir_x = map->player.dir_x * cos(map->player.rotspeed) -
	map->player.dir_y * sin(map->player.rotspeed);
	map->player.dir_y = map->player.old_dir_x * sin(map->player.rotspeed) +
	map->player.dir_y * cos(map->player.rotspeed);
	map->player.old_plane_x = map->player.plane_x;
	map->player.plane_x = map->player.plane_x * cos(map->player.rotspeed) -
	map->player.plane_y * sin(map->player.rotspeed);
	map->player.plane_y = map->player.old_plane_x *
	sin(map->player.rotspeed) + map->player.plane_y *
	cos(map->player.rotspeed);
}
