/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 06:59:51 by epetrill          #+#    #+#             */
/*   Updated: 2020/10/30 16:18:07 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void			ft_initinfo(t_mapinfo *pinfo) // Init struct
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
}

int			ft_fillpath(char *line, t_mapinfo *pinfo, int chx)
{
	if (chx == 3 && pinfo->sprite == NULL)
		pinfo->sprite = ft_strdup(line);
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

int			ft_mapprocess(char **map, t_mapinfo *pinfo)
{
	int i;
	int ret;

	i = 0;
	ret = 1;

	while (map[i] && ret > 0 && ft_checkinf(pinfo))
	{
		if (ft_isparam(map[i]) == 0 && *map[i] != 0)
		{
			ft_putstr(map[i]);
			ft_putstr("\nLes lignes de parametres sont corrompues\n");
			return (-1);
		}
		ret = ft_reachinf(map[i], pinfo);
		i++;
	}
	return (ret);
}
