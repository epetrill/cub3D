/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 03:10:26 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 09:40:48 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int     close_game(t_mapinfo *pinfo)
{
    mlx_destroy_image(pinfo->data.ptr, pinfo->data.img);
    mlx_destroy_window(pinfo->data.ptr, pinfo->data.win);
    ft_freestruct(pinfo);
    exit(1);
}

int		key_release(int code, t_mapinfo *pinfo)
{
    if (code == KEY_UP || code == KEY_Z)
		moving_up(pinfo);
	if (code == KEY_DOWN || code == KEY_S)
		moving_down(pinfo);
	if (code == KEY_Q)
		moving_left(pinfo);
	if (code == KEY_D)
		moving_right(pinfo);
	if (code == KEY_LEFT)
		watching_left(pinfo);
	if (code == KEY_RIGHT)
		watching_right(pinfo);
	return (0);
}

int		key_press(int code, t_mapinfo *pinfo, int choice)
{
    key_release(code, pinfo);
    if(code == KEY_ESC)
    {
        if(choice != 118)
            ft_putstr("Vous avez quitte en appuyant sur echap !\n");
        ft_putstr("Fermeture du jeu !\n");
        return (close_game(pinfo));
    }
    return (0);
}

void	watching_left(t_mapinfo *pinfo)
{
	pinfo->player.old_dir_x = pinfo->player.dir_x;
	pinfo->player.dir_x = pinfo->player.dir_x * cos(-pinfo->player.rotspeed) -
	pinfo->player.dir_y * sin(-pinfo->player.rotspeed);
	pinfo->player.dir_y = pinfo->player.old_dir_x * sin(-pinfo->player.rotspeed) +
	pinfo->player.dir_y * cos(-pinfo->player.rotspeed);
	pinfo->player.old_plane_x = pinfo->player.plane_x;
	pinfo->player.plane_x = pinfo->player.plane_x * cos(-pinfo->player.rotspeed) -
	pinfo->player.plane_y * sin(-pinfo->player.rotspeed);
	pinfo->player.plane_y = pinfo->player.old_plane_x *
	sin(-pinfo->player.rotspeed) + pinfo->player.plane_y *
	cos(-pinfo->player.rotspeed);
}

void	watching_right(t_mapinfo *pinfo)
{
	pinfo->player.old_dir_x = pinfo->player.dir_x;
	pinfo->player.dir_x = pinfo->player.dir_x * cos(pinfo->player.rotspeed) -
	pinfo->player.dir_y * sin(pinfo->player.rotspeed);
	pinfo->player.dir_y = pinfo->player.old_dir_x * sin(pinfo->player.rotspeed) +
	pinfo->player.dir_y * cos(pinfo->player.rotspeed);
	pinfo->player.old_plane_x = pinfo->player.plane_x;
	pinfo->player.plane_x = pinfo->player.plane_x * cos(pinfo->player.rotspeed) -
	pinfo->player.plane_y * sin(pinfo->player.rotspeed);
	pinfo->player.plane_y = pinfo->player.old_plane_x *
	sin(pinfo->player.rotspeed) + pinfo->player.plane_y *
	cos(pinfo->player.rotspeed);
}
