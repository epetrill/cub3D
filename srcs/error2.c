/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:34:49 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/01 21:37:28 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char		**ft_fillmask(char **map, t_mapinfo *pinfo)
{
	char	**tmp;
	int		i;
	int		j;

	ft_colmax(map, pinfo);
	if (!(tmp = malloc((pinfo->lign + 1) * sizeof(*tmp))))
		return (ft_error("Issue during realloc map\n"));
	i = 0;
	while (i < pinfo->lign)
	{
		if (!(tmp[i] = malloc((pinfo->col + 1) * sizeof(*tmp))))
			return (ft_error("Issue during realloc map\n"));
		j = 0;
		while (j < pinfo->col)
		{
			tmp[i][j] = '5';
			j++;
		}
		tmp[i][j] = 0;
		i++;
	}
	tmp[pinfo->lign] = NULL;
	return (tmp);
}

char		**ft_deposemask(char **map, char **mask)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j])
		{
			if (map[i][j] != ' ')
				mask[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	ft_freetab(map);
	return (mask);
}

int			ft_checkfill(char **map, t_mapinfo *pinfo)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '5'
				&& (i == 0 || j == 0 || i == pinfo->lign
				|| j == pinfo->col))
			{
				ft_putstr("La map est ouverte\n");
				return (-1);
			}
			else if (map[i][j] != '1' && map[i][j] != '5'
				&& (map[i - 1][j] == '5' || map[i][j - 1] == '5'
				|| map[i + 1][j] == '5' || map[i][j + 1] == '5'))
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
