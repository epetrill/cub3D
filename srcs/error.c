/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 06:52:36 by epetrill          #+#    #+#             */
/*   Updated: 2020/11/02 16:08:57 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char		**ft_error(char *str) // Error chaine de carac
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
	else if (pinfo->floor_r > 255 || pinfo->floor_g > 255 || pinfo->floor_b > 255
		|| pinfo->ceil_r > 255 || pinfo->ceil_g > 255 || pinfo->ceil_b > 255)
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
		j = 0;
		while (map[i][j] != '\n' && map[i][j])
		{
			if (start == 0 && (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E'))
				start = 1;
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
			if (map[i][j] != '1' && map[i][j] != '5' && (map[i - 1][j] == '5' 
				|| map[i][j - 1] == '5' || map[i + 1][j] == '5'
				|| map[i][j + 1] == '5'))
				ft_putstr("La map est ouverte !\n");
			j++;
		}
		i++;
	}
}