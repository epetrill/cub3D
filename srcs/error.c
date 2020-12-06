/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 06:52:36 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/02 20:31:24 by epetrill         ###   ########lyon.fr   */
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

int			ft_checkmap(char **map, int start, int i, t_mapinfo *pinfo)
{
	int j;

	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j])
		{
			if (start == 0 && (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E'))
			{
				start = 1;
				pinfo->start_x = i;
				pinfo->start_y = j;
			}
			else if (start == 1 && (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E'))
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

int			ft_checkmap2(char **map, t_mapinfo *pinfo)
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
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'N'
				&& map[i][j] != 'S' && map[i][j] != 'W' && map[i][j] != 'E'
				&& map[i][j] != ' ' && map[i][j] != '\n' && map[i][j] != '2')
			{
				ft_putstr("Caractere impossible dans la map !\n");
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (ft_checkmap(map, 0, 0, pinfo));
}

int			*ft_colmax(char **map, t_mapinfo *pinfo)
{
	int i;

	i = 0;
	while (map[pinfo->lign])
	{
		i = 0;
		while (map[pinfo->lign][i] != '\n' && map[pinfo->lign][i])
			i++;
		if (i > pinfo->col)
			pinfo->col = i;
		pinfo->lign++;
	}
	return (0);
}
