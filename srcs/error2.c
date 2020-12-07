/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:34:49 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 20:27:59 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char		**ft_fillmask(t_mapinfo *map)
{
	char	**tmp;
	int		i;
	int		j;

	ft_colmax(map);
	if (!(tmp = malloc((map->lign + 1) * sizeof(*tmp))))
		return (ft_error("Issue during realloc map\n"));
	i = 0;
	while (i < map->lign)
	{
		if (!(tmp[i] = malloc((map->col + 1) * sizeof(*tmp))))
			return (ft_error("Issue during realloc map\n"));
		j = 0;
		while (j < map->col)
		{
			tmp[i][j] = '5';
			j++;
		}
		tmp[i][j] = 0;
		i++;
	}
	tmp[map->lign] = NULL;
	return (tmp);
}

char		**ft_deposemask(char **mask, t_mapinfo *map)
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
			if (map->map[i][j] != ' ')
				mask[i][j] = map->map[i][j];
			if (map->map[i][j] == '2')
				map->counter_sprite++;
			j++;
		}
		i++;
	}
	ft_freetab(map->map);
	return (mask);
}

int			ft_checkfill(t_mapinfo *map, int i, int j)
{
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j] != '\n' && map->map[i][j])
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '5'
				&& (i == 0 || j == 0 || i == map->lign
				|| j == map->col))
			{
				ft_putstr("La map est ouverte\n");
				return (-1);
			}
			else if (map->map[i][j] != '1' && map->map[i][j] != '5'
				&& (map->map[i - 1][j] == '5' || map->map[i][j - 1] == '5'
				|| map->map[i + 1][j] == '5' || map->map[i][j + 1] == '5'))
			{
				ft_putstr("La map est ouverte !\n");
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
