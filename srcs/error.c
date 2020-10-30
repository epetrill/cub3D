/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 06:52:36 by epetrill          #+#    #+#             */
/*   Updated: 2020/10/30 01:25:57 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char		**ft_error(char *str) // Error chaine de carac
{
	ft_putstr("Error\n");
	ft_putstr(str);
	return (NULL);
}

int			ft_checkinf(t_mapinfo info)
{
	if (info.res[0] < 0 || info.res[1] < 0 || info.north == NULL
		|| info.south == NULL || info.floor[1] < 0 || info.floor[0] < 0
		|| info.south == NULL || info.east == NULL || info.west == NULL
		|| info.sprite == NULL || info.floor[2] < 0 || info.ceil[2] < 0
		|| info.ceil[1] < 0 || info.ceil[0] < 0)
		return (-1);
	else if (info.floor[0] > 255 || info.floor[1] > 255 || info.floor[2] > 255
		|| info.ceil[0] > 255 || info.ceil[1] > 255 || info.ceil[2] > 255)
		return (-1);
	return (0);
}

int			ft_checkmap(char **map)
{
	int i;
	int j;
	int start;

	i = 0;
	j = 0;
	start = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != 'N' && map[i][j] != 'S'
				&& map[i][j] != 'W' && map[i][j] != 'E')
				start = 1;
			if (start == 1 && (map[i][j] == 'N' || map[i][j] == 'S'
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

int			ft_checkmap2(char **map)
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
	return (ft_checkmap(map));
}

int			*ft_colmax(char **map)
{
	int i;
	int *val;

	i = 0;
	if (!(val = malloc((2) * sizeof(*val))))
	{
		ft_putstr("Issue during malloc\n");
		return (NULL);
	}
	val[1] = 0;
	val[0] = 0;
	while (map[val[1]])
	{
		i = 0;
		while (map[val[1]][i] != '\n' && map[val[1]][i])
			i++;
		if (i > val[0])
			val[0] = i;
		val[1]++;
	};
	return (val);
}

char		**ft_fillmask(char **map)
{
	char	**tmp;
	int		*val;
	int		i;
	int		j;

	val = ft_colmax(map);
	if (!(tmp = malloc((val[1] + 1) * sizeof(*tmp))))
		return (ft_error("Issue during realloc map\n"));
	i = 0;
	while (i < val[1])
	{
		if (!(tmp[i] = malloc((val[0] + 1) * sizeof(*tmp))))
			return (ft_error("Issue during realloc map\n"));
		j = 0;
		while (j < val[0])
		{
			tmp[i][j] = '5';
			j++;
		}
		tmp[i][j] = 0;
		i++;
	}
	tmp[val[1]] = NULL;
	free(val);
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

void		ft_checkfill(char **map)
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
			if (map[i][j] == '0' && (map[i - 1][j] == '5' 
				|| map[i][j - 1] == '5' || map[i + 1][j] == '5'
				|| map[i][j + 1] == '5'))
				ft_putstr("La map est ouverte !\n");
			j++;
		}
		i++;
	}
}