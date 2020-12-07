/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 06:52:36 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 20:36:02 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char		**ft_error(char *str)
{
	ft_putstr("Error\n");
	ft_putstr(str);
	return (NULL);
}

int			ft_checkinf(t_mapinfo *map)
{
	if (map->res_x < 0 || map->res_y < 0 || map->north == NULL
		|| map->south == NULL || map->floor_g < 0 || map->floor_r < 0
		|| map->south == NULL || map->east == NULL || map->west == NULL
		|| map->sprite == NULL || map->floor_b < 0 || map->ceil_b < 0
		|| map->ceil_g < 0 || map->ceil_r < 0)
		return (-1);
	else if (map->floor_r > 255 || map->floor_g > 255
		|| map->floor_b > 255 || map->ceil_r > 255
		|| map->ceil_g > 255 || map->ceil_b > 255)
		return (-1);
	return (0);
}

int			ft_checkmap(int start, int i, t_mapinfo *map)
{
	int j;

	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j] != '\n' && map->map[i][j])
		{
			if (start == 0 && (ft_iscardi(map->map[i][j])))
			{
				start = 1;
				ft_startpos(map, map->map[i][j], i, j);
			}
			else if (start == 1 && (ft_iscardi(map->map[i][j])))
			{
				ft_putstr("Plusieurs positions de depart !\n");
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int			ft_checkmap2(t_mapinfo *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j] != '\n' && map->map[i][j])
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '0' &&
			!(ft_iscardi(map->map[i][j])) && map->map[i][j] != ' '
			&& map->map[i][j] != '\n' && map->map[i][j] != '2')
			{
				ft_putstr("Caractere impossible dans la map !\n");
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (ft_checkmap(0, 0, map));
}

int			*ft_colmax(t_mapinfo *map)
{
	int i;

	i = 0;
	while (map->map[map->lign])
	{
		i = 0;
		while (map->map[map->lign][i] != '\n' && map->map[map->lign][i])
			i++;
		if (i > map->col)
			map->col = i;
		map->lign++;
	}
	return (0);
}
