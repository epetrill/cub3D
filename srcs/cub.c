/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 06:48:54 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/06 03:43:45 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char	**ft_cleanmap(char **map)
{
	int i;
	int j;

	i = 0;
	while (*map[i] == 0 || ft_isparam(map[i]))
	{
		if (*map[i + 1] != 0 && ft_isparam(map[i + 1]) == 0
			&& *map[i + 1] != '1' && *map[i + 1] != ' ')
		{
			ft_putstr("Il y a trop de parametres !\n");
			return (map);
		}
		i++;
	}
	j = i;
	while (*map[j])
		j++;
	map = ft_avoidpar(map, i, j - i + 1);
	return (map);
}

char	**ft_avoidpar(char **map, int i, int size)
{
	int		j;
	char	**map2;

	j = i;
	if (!(map2 = malloc((size + 1) * sizeof(void *))))
		return (ft_error("Issue during malloc map lines"));
	while (j-- > 0)
		free(map[j]);
	j = 0;
	while (map[i])
		map2[j++] = map[i++];
	map2[j] = NULL;
	free(map);
	return (map2);
}

int		ft_coor(char *buff, t_mapinfo *pinfo)
{
	char		**map;
	char		**tmp;
	int			ret;

	map = NULL;
	tmp = NULL;
	if ((map = ft_cpymap(buff, map)) == NULL)
		return (0);
	ret = ft_mapprocess(map, pinfo);
	if (ret >= 0)
	{
		map = ft_cleanmap(map);
		ret = ft_checkmap2(map, pinfo);
	}
	if (ret >= 0)
	{
		tmp = ft_fillmask(map, pinfo);
		map = ft_deposemask(map, tmp);
		ret = ret || ft_checkfill(map, pinfo, 0, 0);
	}
	ft_afftab(map);
	ft_freetab(map);
	ft_freestruct(pinfo);
	return (ret);
}

int		main(int ac, char **av)
{
	t_mapinfo	info;
	int			ret;

	ret = 0;
	ft_bzero(&info, sizeof(info));
	ft_initinfo(&info);
	if (ac != 2)
	{
		ft_putstr("Wrong arg nbrs for ./cub\n");
		return (-1);
	}
	else
	{
		ret = ft_coor(av[1], &info);
		if (ret < 0)
			return (-1);
		mlx_shit(&info);
	}
	return (0);
}
