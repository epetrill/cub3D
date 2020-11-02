/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filetotab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 07:01:32 by epetrill          #+#    #+#             */
/*   Updated: 2020/10/30 16:34:04 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_freetab(char **map)// Liberez le tableau en fin de processus
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	if (map)
		free(map);
	map = NULL;
}

char	**ft_cpymap(char *fichier, char **map)//Fichier texte -> tableau
{
	int gnl_ret;
	int fd;
	int len;

	len = ft_strlen(fichier);
	gnl_ret = 1;
	fd = 0;
	if (!(map = malloc(2 * (sizeof(*map)))))
		return (ft_error("Issue during malloc map lines"));
	map[0] = NULL;
	map[1] = NULL;
	if (len < 5 || ft_strncmp(".cub", &fichier[len - 4], 4) != 0)
		return (ft_error("Issue with the map name\n"));
	len = 0;
	if (!(fd = open(fichier, O_RDONLY)))
		return (ft_error("Issue during file opening\n"));
	while (gnl_ret)
	{
		gnl_ret = get_next_line(fd, &map[len]);
		len++;
		if ((map = ft_realloc(map, len + 1)) == NULL)
			return (NULL);
	}
	return (map);
}

char	**ft_realloc(char **map, int size)
{
	char	**tmp;
	int		i;

	i = 0;
	if (!(tmp = malloc((size + 1) * sizeof(*tmp))))
		return (ft_error("Issue during realloc map\n"));
	while (map[i])
	{
		tmp[i] = ft_strdup(map[i]);
		i++;
	}
	tmp[size - 1] = NULL;
	tmp[size] = NULL;
	ft_freetab(map);
	return (tmp);
}

void	ft_afftab(char **map) // Afficher un tableau 2 dim
{
	int i;

	i = 0;
	while (map[i])
	{
		printf("|%s|\n", map[i]);
		//free(map[i]);
		i++;
	}
	//free(map[i]);
	//free(map);
}
