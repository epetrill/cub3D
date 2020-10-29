/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 06:48:54 by epetrill          #+#    #+#             */
/*   Updated: 2020/10/29 20:33:24 by epetrill         ###   ########lyon.fr   */
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
	map = ft_avoidpar(map, i, j - i);
	return (map);
}

char	**ft_avoidpar(char **map, int i, int size)
{
	int		j;
	char	**map2;

	j = 0;
	map2 = NULL;
	if (!(map2 = malloc((size + 1) * sizeof(*map2))))
		return (ft_error("Issue during malloc map lines"));
	while (map[i])
	{
		map2[j] = ft_strdup(map[i]);
		i++;
		j++;
	}
	map2[size] = NULL;
	//map = ft_freetab(map); //erreur "double free..."
	return (map2);
}

int		ft_coor(char *buff)
{
	char		**map;
	t_mapinfo	*pinfo;
	int			ret;

	map = NULL;
	pinfo = NULL;
	if ((map = ft_cpymap(buff, map)) == NULL)
		return (0);
	ret = ft_mapprocess(map, pinfo);
	if (ret >= 0)
		map = ft_cleanmap(map);
	ret = ft_checkmap2(map);
	
	ft_afftab(map);
	map = ft_freetab(map);
	//pinfo = ft_freestruct(pinfo);
	//printf("%d\n", ret);
	return (ret);
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr("Wrong arg nbrs for ./cub\n");
		return (-1);
	}
	return (ft_coor(av[1]));
}
