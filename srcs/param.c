/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 06:59:51 by epetrill          #+#    #+#             */
/*   Updated: 2020/10/29 08:31:11 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int			ft_initinfo(t_mapinfo **pinfo) // Init struct
{
	t_mapinfo *info;

	if (!(info = malloc(sizeof(t_mapinfo))))
	{
		ft_putstr("Issue during struc info malloc\n");
		return (-2);
	}
	if (!(info->res = malloc(sizeof(int) * 2)))
	{
		ft_putstr("Issue during struc info malloc\n");
		return (-2);
	}
	if (!(info->floor = malloc(sizeof(int) * 3)))
	{
		ft_putstr("Issue during struc info malloc\n");
		return (-2);
	}
	if (!(info->ceil = malloc(sizeof(int) * 3)))
	{
		ft_putstr("Issue during struc info malloc\n");
		return (-2);
	}
	*pinfo = ft_initinfo2(info);
	return (0);
}

t_mapinfo	*ft_initinfo2(t_mapinfo *info)
{
	info->res[0] = -1;
	info->res[1] = -1;
	info->north = NULL;
	info->south = NULL;
	info->east = NULL;
	info->west = NULL;
	info->sprite = NULL;
	info->floor[0] = -1;
	info->floor[1] = -1;
	info->floor[2] = -1;
	info->ceil[0] = -1;
	info->ceil[1] = -1;
	info->ceil[2] = -1;
	return (info);
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
		printf("chx = %d\n", chx);
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
	if (ft_initinfo(&pinfo) == 0)
		while (map[i] && ret > 0 && ft_checkinf(*pinfo))
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
	else
		return (-1);
	return (ret);
}
