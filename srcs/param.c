/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 06:59:51 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 02:18:31 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void		ft_initinfo(t_mapinfo *pinfo)
{
	pinfo->res_x = -1;
	pinfo->res_y = -1;
	pinfo->north = NULL;
	pinfo->south = NULL;
	pinfo->east = NULL;
	pinfo->west = NULL;
	pinfo->sprite = NULL;
	pinfo->floor_r = -1;
	pinfo->floor_g = -1;
	pinfo->floor_b = -1;
	pinfo->ceil_r = -1;
	pinfo->ceil_g = -1;
	pinfo->ceil_b = -1;
	pinfo->lign = 0;
	pinfo->col = 0;
}

int			ft_fillpath(char *line, t_mapinfo *pinfo, int chx)
{
	if (chx == 3 && pinfo->sprite == NULL)
		pinfo->path_sprites = ft_strdup(line);
	else if (chx == 4 && pinfo->north == NULL)
		pinfo->north = ft_strdup(line);
	else if (chx == 5 && pinfo->south == NULL)
		pinfo->south = ft_strdup(line);
	else if (chx == 6 && pinfo->west == NULL)
		pinfo->west = ft_strdup(line);
	else if (chx == 7 && pinfo->east == NULL)
		pinfo->east = ft_strdup(line);
	else
	{
		ft_putstr("Parametre en double !\n");
		return (-1);
	}
	return (0);
}

int			ft_mapprocess(t_mapinfo *pinfo)
{
	int i;
	int ret;

	i = 0;
	ret = 1;
	while (pinfo->map[i] && ret > 0 && ft_checkinf(pinfo))
	{
		ret = ft_reachinf(pinfo->map[i], pinfo);
		i++;
	}
	return (ret);
}
