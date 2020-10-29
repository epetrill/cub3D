/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapprep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 06:58:21 by epetrill          #+#    #+#             */
/*   Updated: 2020/10/29 08:31:22 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int			ft_reachc(char *line, t_mapinfo *pinfo)
{
	line++;
	while (*line == ' ')
		line++;
	pinfo->ceil[0] = (ft_atoimod(line, 1) >= 0) ? ft_atoimod(line, 1) : -1;
	line = line + ft_nblen(line);
	while (*line == ' ')
		line++;
	pinfo->ceil[1] = (ft_atoimod(line, 1) >= 0) ? ft_atoimod(line, 1) : -1;
	line = line + ft_nblen(line);
	while (*line == ' ')
		line++;
	pinfo->ceil[2] = (ft_atoimod(line, 1) >= 0) ? ft_atoimod(line, 1) : -1;
	return (0);
}

int			ft_reachres(char *line, t_mapinfo *pinfo)
{
	line++;
	while (*line == ' ')
		line++;
	pinfo->res[0] = ft_atoimod(line, 0);
	line = line + ft_nblen(line);
	while (*line == ' ')
		line++;
	pinfo->res[1] = ft_atoimod(line, 0);
	return (1);
}

int			ft_reachf(char *line, t_mapinfo *pinfo)
{
	line++;
	while (*line == ' ')
		line++;
	pinfo->floor[0] = (ft_atoimod(line, 1) >= 0) ? ft_atoimod(line, 1) : -1;
	line = line + ft_nblen(line);
	while (*line == ' ')
		line++;
	pinfo->floor[1] = (ft_atoimod(line, 1) >= 0) ? ft_atoimod(line, 1) : -1;
	line = line + ft_nblen(line);
	while (*line == ' ')
		line++;
	pinfo->floor[2] = (ft_atoimod(line, 1) >= 0) ? ft_atoimod(line, 1) : -1;
	return (0);
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
	return (1);
}
