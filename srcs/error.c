/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 06:52:36 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 02:44:27 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char		**ft_error(char *str)
{
	ft_putstr("Error\n");
	ft_putstr(str);
	return (NULL);
}

int			ft_checkinf(t_mapinfo *pinfo)
{
	if (pinfo->res_x < 0 || pinfo->res_y < 0 || pinfo->north == NULL
		|| pinfo->south == NULL || pinfo->floor_g < 0 || pinfo->floor_r < 0
		|| pinfo->south == NULL || pinfo->east == NULL || pinfo->west == NULL
		|| pinfo->sprite == NULL || pinfo->floor_b < 0 || pinfo->ceil_b < 0
		|| pinfo->ceil_g < 0 || pinfo->ceil_r < 0)
		return (-1);
	else if (pinfo->floor_r > 255 || pinfo->floor_g > 255
		|| pinfo->floor_b > 255 || pinfo->ceil_r > 255
		|| pinfo->ceil_g > 255 || pinfo->ceil_b > 255)
		return (-1);
	return (0);
}

int			ft_checkmap(int start, int i, t_mapinfo *pinfo)
{
	int j;

	while (pinfo->map[i])
	{
		j = 0;
		while (pinfo->map[i][j] != '\n' && pinfo->map[i][j])
		{
			if (start == 0 && (pinfo->map[i][j] == 'N' || pinfo->map[i][j] == 'S'
				|| pinfo->map[i][j] == 'W' || pinfo->map[i][j] == 'E'))
			{
				start = 1;
				ft_startpos(pinfo, pinfo->map[i][j], i, j);
			}
			else if (start == 1 && (pinfo->map[i][j] == 'N' || pinfo->map[i][j] == 'S'
				|| pinfo->map[i][j] == 'W' || pinfo->map[i][j] == 'E'))
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

int			ft_checkmap2(t_mapinfo *pinfo)
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
			if (pinfo->map[i][j] != '1' && pinfo->map[i][j] != '0' && pinfo->map[i][j] != 'N'
				&& pinfo->map[i][j] != 'S' && pinfo->map[i][j] != 'W' && pinfo->map[i][j] != 'E'
				&& pinfo->map[i][j] != ' ' && pinfo->map[i][j] != '\n' && pinfo->map[i][j] != '2')
			{
				ft_putstr("Caractere impossible dans la map !\n");
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (ft_checkmap(0, 0, pinfo));
}

int			*ft_colmax(t_mapinfo *pinfo)
{
	int i;

	i = 0;
	while (pinfo->map[pinfo->lign])
	{
		i = 0;
		while (pinfo->map[pinfo->lign][i] != '\n' && pinfo->map[pinfo->lign][i])
			i++;
		if (i > pinfo->col)
			pinfo->col = i;
		pinfo->lign++;
	}
	return (0);
}
