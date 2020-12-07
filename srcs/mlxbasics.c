/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxbasics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 21:40:36 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 20:47:50 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		main_loop(t_mapinfo *map)
{
	launcher(map);
	spriter(map);
	designer(map);
	return (0);
}

void	resize_res(t_mapinfo *map)
{
	int	resx;
	int	resy;

	mlx_get_screen_size(map->data.ptr, &resx, &resy);
	if (map->res_x > resx)
		map->res_x = resx;
	if (map->res_y > resy)
		map->res_y = resy;
}

int		cross_close(t_mapinfo *map)
{
	ft_putstr("Vous avez quitte avec la croix !\n");
	return (key_press(KEY_ESC, map, 118));
}

int		mlx_shit(t_mapinfo *map)
{
	if ((map->data.ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	resize_res(map);
	buffer_init(map);
	texture_init(map);
	sprite_init(map);
	tex_loader(map);
	angle_setter(map);
	if ((map->data.win = mlx_new_window(map->data.ptr, map->res_x, map->res_y
	, "fast")) == NULL)
		return (-1);
	if ((map->data.img = mlx_new_image(map->data.ptr, map->res_x, map->res_y))
	== NULL)
		return (-1);
	if ((map->data.img_data = (int *)mlx_get_data_addr(map->data.img,
	&map->data.bpp, &map->data.size_l, &map->data.endian)) == NULL)
		return (-1);
	mlx_hook(map->data.win, 3, 1, &key_release, map);
	mlx_hook(map->data.win, 2, 1, &key_press, map);
	mlx_hook(map->data.win, 33, 0, &cross_close, map);
	mlx_loop_hook(map->data.ptr, &main_loop, map);
	mlx_loop(map->data.ptr);
	return (0);
}
