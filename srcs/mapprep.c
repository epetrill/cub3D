/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapprep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 06:58:21 by epetrill          #+#    #+#             */
/*   Updated: 2020/10/30 16:06:58 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int			ft_reachc(char *line, t_mapinfo *pinfo)
{
	if (pinfo->ceil_r == -1 && pinfo->ceil_g == -1 && pinfo->ceil_b == -1)
	{
		line++;
		while (*line == ' ')
			line++;
		pinfo->ceil_r = (ft_atoimod(line, 1) >= 0) ? ft_atoimod(line, 1) : -1;
		line = line + ft_nblen(line);
		while (*line == ' ')
			line++;
		pinfo->ceil_g = (ft_atoimod(line, 1) >= 0) ? ft_atoimod(line, 1) : -1;
		line = line + ft_nblen(line);
		while (*line == ' ')
			line++;
		pinfo->ceil_b = (ft_atoimod(line, 1) >= 0) ? ft_atoimod(line, 1) : -1;
	}
	else
	{
		ft_putstr("Couleur du ciel en double !\n");
		return (-2);
	}
	return (0);
}

int			ft_reachres(char *line, t_mapinfo *pinfo)
{	if (pinfo->res_x == -1 && pinfo->res_y == -1)
	{
		line++;
		while (*line == ' ')
			line++;
		pinfo->res_x = ft_atoimod(line, 0);
		line = line + ft_nblen(line);
		while (*line == ' ')
			line++;
		pinfo->res_y = ft_atoimod(line, 0);
		return (1);
	}
	else
	{
		ft_putstr("Resolution en double !\n");
		return (-2);
	}
}

int			ft_reachf(char *line, t_mapinfo *pinfo)
{
	if (pinfo->floor_r == -1 && pinfo->floor_g == -1 && pinfo->floor_b == -1)
	{
		line++;
		while (*line == ' ')
			line++;
		pinfo->floor_r = (ft_atoimod(line, 1) >= 0) ? ft_atoimod(line, 1) : -1;
		line = line + ft_nblen(line);
		while (*line == ' ')
			line++;
		pinfo->floor_g = (ft_atoimod(line, 1) >= 0) ? ft_atoimod(line, 1) : -1;
		line = line + ft_nblen(line);
		while (*line == ' ')
			line++;
		pinfo->floor_b = (ft_atoimod(line, 1) >= 0) ? ft_atoimod(line, 1) : -1;
		return (0);
	}
	else
	{
		ft_putstr("Couleur du sol en double !\n");
		return (-2);
	}
	
}

int			ft_reachwall(char *line, t_mapinfo *pinfo, int chx)
{
	int ret;

	ret = 0;
	line = line + 2;
	while (*line == ' ')
		line++;
	ret = ft_fillpath(line, pinfo, chx);
	if (ret < 0)
		return (-4);
	line = line + ft_wlen(line);
	return (0);
}

int			ft_reachinf(char *line, t_mapinfo *pinfo)
{
	int ret;

	ret = ft_isparam(line);
	if (ret == 1)
		ret = ft_reachres(line, pinfo);
	else if (ret > 2)
		ret = ft_reachwall(line, pinfo, ret);
	else if (ret == 2)
	{
		if (*line == 'C')
			ret = ft_reachc(line, pinfo);
		else
			ret = ft_reachf(line, pinfo);
	}
	if (ret < 0)
		return (-1);
	return (1);
}
