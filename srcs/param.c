/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 06:59:51 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 20:27:59 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void		ft_initinfo(t_mapinfo *map)
{
	map->res_x = -1;
	map->res_y = -1;
	map->north = NULL;
	map->south = NULL;
	map->east = NULL;
	map->west = NULL;
	map->sprite = NULL;
	map->floor_r = -1;
	map->floor_g = -1;
	map->floor_b = -1;
	map->ceil_r = -1;
	map->ceil_g = -1;
	map->ceil_b = -1;
	map->lign = 0;
	map->col = 0;
}

int			ft_fillpath(char *line, t_mapinfo *map, int chx)
{
	if (chx == 3 && map->sprite == NULL)
		map->path_sprites = ft_strdup(line);
	else if (chx == 4 && map->north == NULL)
		map->north = ft_strdup(line);
	else if (chx == 5 && map->south == NULL)
		map->south = ft_strdup(line);
	else if (chx == 6 && map->west == NULL)
		map->west = ft_strdup(line);
	else if (chx == 7 && map->east == NULL)
		map->east = ft_strdup(line);
	else
	{
		ft_putstr("Parametre en double !\n");
		return (-1);
	}
	return (0);
}

int			ft_mapprocess(t_mapinfo *map)
{
	int i;
	int ret;

	i = 0;
	ret = 1;
	while (map->map[i] && ret > 0 && ft_checkinf(map))
	{
		ret = ft_reachinf(map->map[i], map);
		i++;
	}
	return (ret);
}
