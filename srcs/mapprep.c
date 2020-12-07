/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapprep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 06:58:21 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 20:57:16 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int			ft_reachc(char *line, t_mapinfo *map)
{
	if (map->ceil_r == -1 && map->ceil_g == -1 && map->ceil_b == -1)
	{
		line++;
		while (*line == ' ')
			line++;
		map->ceil_r = (ft_atoimod(line, 1) >= 0) ? ft_atoimod(line, 1) : -1;
		line = line + ft_nblen(line);
		while (*line == ' ')
			line++;
		map->ceil_g = (ft_atoimod(line, 1) >= 0) ? ft_atoimod(line, 1) : -1;
		line = line + ft_nblen(line);
		while (*line == ' ')
			line++;
		map->ceil_b = (ft_atoimod(line, 1) >= 0) ? ft_atoimod(line, 1) : -1;
	}
	else
	{
		ft_putstr("Couleur du ciel en double !\n");
		return (-2);
	}
	return (0);
}

int			ft_reachres(char *line, t_mapinfo *map)
{
	if (map->res_x == -1 && map->res_y == -1)
	{
		line++;
		while (*line == ' ')
			line++;
		map->res_x = ft_atoimod(line, 0);
		line = line + ft_nblen(line);
		while (*line == ' ')
			line++;
		map->res_y = ft_atoimod(line, 0);
		return (1);
	}
	else
	{
		ft_putstr("Resolution en double !\n");
		return (-2);
	}
}

int			ft_reachf(char *line, t_mapinfo *map)
{
	if (map->floor_r == -1 && map->floor_g == -1 && map->floor_b == -1)
	{
		line++;
		while (*line == ' ')
			line++;
		map->floor_r = (ft_atoimod(line, 1) >= 0) ? ft_atoimod(line, 1) : -1;
		line = line + ft_nblen(line);
		while (*line == ' ')
			line++;
		map->floor_g = (ft_atoimod(line, 1) >= 0) ? ft_atoimod(line, 1) : -1;
		line = line + ft_nblen(line);
		while (*line == ' ')
			line++;
		map->floor_b = (ft_atoimod(line, 1) >= 0) ? ft_atoimod(line, 1) : -1;
		return (0);
	}
	else
	{
		ft_putstr("Couleur du sol en double !\n");
		return (-2);
	}
}

int			ft_reachwall(char *line, t_mapinfo *map, int chx)
{
	int ret;

	ret = 0;
	line = line + 2;
	while (*line == ' ')
		line++;
	ret = ft_fillpath(line, map, chx);
	if (ret < 0)
		return (-4);
	line = line + ft_wlen(line);
	return (0);
}

int			ft_reachinf(char *line, t_mapinfo *map)
{
	int ret;

	ret = ft_isparam(line);
	if (ret == 1)
		ret = ft_reachres(line, map);
	else if (ret > 2)
		ret = ft_reachwall(line, map, ret);
	else if (ret == 2)
	{
		if (*line == 'C')
			ret = ft_reachc(line, map);
		else
			ret = ft_reachf(line, map);
	}
	if (ret < 0)
		return (-1);
	return (1);
}
