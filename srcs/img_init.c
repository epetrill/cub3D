/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 01:22:22 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 20:55:41 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		buffer_init(t_mapinfo *map)
{
	int val;
	int pos;

	val = 0;
	pos = 0;
	if (!(map->buffer = (int **)malloc(sizeof(int *) * map->res_y)))
		return (0);
	while (pos < map->res_y)
	{
		map->buffer[pos] = ft_calloc(map->res_x, sizeof(int));
		pos++;
	}
	map->spribuf = ft_calloc(map->res_x, sizeof(double *));
	return (1);
}

int		texture_init(t_mapinfo *map)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	if (!(map->tex = (int **)malloc(sizeof(int *) * 5)))
		return (-1);
	while (i < 5)
	{
		if (!(map->tex[i] = (int *)malloc(sizeof(int) * (WIDTH * HEIGHT))))
			return (-1);
		while (j < WIDTH * HEIGHT)
		{
			map->tex[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int		sprite_init(t_mapinfo *map)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	if (!(map->sprite = (t_sprite *)malloc(sizeof(t_sprite)
		* map->counter_sprite)))
		return (0);
	while (y < map->lign)
	{
		while (x < map->col)
		{
			if (map->map[y][x] == '2')
			{
				sprite_usher(map, i, x, y);
				i++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

void	sprite_usher(t_mapinfo *map, int i, int x, int y)
{
	map->sprite[i].x = 0.5f + x;
	map->sprite[i].y = 0.5f + y;
}

void	img_loader(t_mapinfo *map, int *texture, char *path)
{
	int y;
	int x;

	y = 0;
	x = 0;
	map->data.img = mlx_xpm_file_to_image(map->data.ptr, path,
	&map->data.img_width, &map->data.img_height);
	map->data.img_data = (int *)mlx_get_data_addr(map->data.img,
	&map->data.bpp, &map->data.size_l, &map->data.endian);
	while (y < map->data.img_height)
	{
		while (x < map->data.img_width)
		{
			texture[map->data.img_width * y + x] =
			map->data.img_data[map->data.img_width * y + x];
			x++;
		}
		x = 0;
		y++;
	}
	mlx_destroy_image(map->data.ptr, map->data.img);
}
