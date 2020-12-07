/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 01:22:22 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 10:35:38 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int         buffer_init(t_mapinfo *pinfo)
{
    int val;
    int pos;

    val = 0;
    pos = 0;
    if(!(pinfo->buffer = (int **)malloc(sizeof(int *) * pinfo->res_y)))
        return (0);
    while (pos < pinfo->res_y)
    {
        pinfo->buffer[pos] = ft_calloc(pinfo->res_x, sizeof(int));
        pos++;
    }
    pinfo->spribuf = ft_calloc(pinfo->res_x, sizeof(double *));
    return (1);
}

int		texture_init(t_mapinfo *pinfo)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	if (!(pinfo->tex = (int **)malloc(sizeof(int *) * 5)))
		return (-1);
	while (i < 5)
	{
		if (!(pinfo->tex[i] = (int *)malloc(sizeof(int) * (WIDTH * HEIGHT))))
			return (-1);
		while (j < WIDTH * HEIGHT)
		{
			pinfo->tex[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int		sprite_init(t_mapinfo *pinfo)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	if (!(pinfo->sprite = (t_sprite *)malloc(sizeof(t_sprite)
		* pinfo->counter_sprite)))
		return (0);
	while (y < pinfo->lign)
	{
		while (x < pinfo->col)
		{
			if (pinfo->map[y][x] == '2')
			{
				sprite_usher(pinfo, i, x, y);
				i++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

void      sprite_usher(t_mapinfo *pinfo, int i, int x, int y)
{
    pinfo->sprite[i].x = 0.5f + x;
    pinfo->sprite[i].y = 0.5f + y;
}

void	img_loader(t_mapinfo *pinfo, int *texture, char *path)
{
	int y;
	int x;

	y = 0;
	x = 0;
	pinfo->data.img = mlx_xpm_file_to_image(pinfo->data.ptr, path,
	&pinfo->data.img_width, &pinfo->data.img_height);
	pinfo->data.img_data = (int *)mlx_get_data_addr(pinfo->data.img,
	&pinfo->data.bpp, &pinfo->data.size_l, &pinfo->data.endian);
	while (y < pinfo->data.img_height)
	{
		while (x < pinfo->data.img_width)
		{
			texture[pinfo->data.img_width * y + x] =
			pinfo->data.img_data[pinfo->data.img_width * y + x];
			x++;
		}
		x = 0;
		y++;
	}
	mlx_destroy_image(pinfo->data.ptr, pinfo->data.img);
}