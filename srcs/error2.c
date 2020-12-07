/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:34:49 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 10:23:42 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char		**ft_fillmask(t_mapinfo *pinfo)
{
	char	**tmp;
	int		i;
	int		j;

	ft_colmax(pinfo);
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

char		**ft_deposemask(char **mask, t_mapinfo *pinfo)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (pinfo->map[i])
	{
		j = 0;
		while (pinfo->map[i][j] != '\n' && pinfo->map[i][j])
		{
			if (pinfo->map[i][j] != ' ')
				mask[i][j] = pinfo->map[i][j];
			if (pinfo->map[i][j] == '2')
				pinfo->counter_sprite++;
			j++;
		}
		i++;
	}
	ft_freetab(pinfo->map);
	return (mask);
}

int			ft_checkfill(t_mapinfo *pinfo, int i, int j)
{
	while (pinfo->map[i])
	{
		j = 0;
		while (pinfo->map[i][j] != '\n' && pinfo->map[i][j])
		{
			if (pinfo->map[i][j] != '1' && pinfo->map[i][j] != '5'
				&& (i == 0 || j == 0 || i == pinfo->lign
				|| j == pinfo->col))
			{
				ft_putstr("La map est ouverte\n");
				return (-1);
			}
			else if (pinfo->map[i][j] != '1' && pinfo->map[i][j] != '5'
				&& (pinfo->map[i - 1][j] == '5' || pinfo->map[i][j - 1] == '5'
				|| pinfo->map[i + 1][j] == '5' || pinfo->map[i][j + 1] == '5'))
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
