/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbasic3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 07:12:09 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 20:43:36 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
		str[i++] = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;
	size_t	stock;

	stock = count * size;
	if (!(tab = malloc(stock)))
		return (NULL);
	ft_bzero(tab, stock);
	return (tab);
}

int		ft_isthing(char c)
{
	if (c != '0' && c != ' ' && c != '1' && c != '2' && c != '\n')
		return (0);
	return (1);
}

void	ft_startpos(t_mapinfo *map, char c, int i, int j)
{
	map->start_x = i;
	map->start_y = j;
	if (c == 'N')
		map->cardinal = 1;
	else if (c == 'W')
		map->cardinal = 2;
	else if (c == 'E')
		map->cardinal = 4;
	else if (c == 'S')
		map->cardinal = 3;
	map->player.pos_x = (float)map->start_x + 0.5;
	map->player.pos_y = (float)map->start_y + 0.5;
}

void	ft_rgbtohex(t_mapinfo *map)
{
	map->hexfloor = ((map->floor_r & 0x0ff) << 16)
	| ((map->floor_g & 0x0ff) << 8)
	| ((map->floor_b & 0x0ff));
	map->hexceil = ((map->ceil_r & 0x0ff) << 16)
	| ((map->ceil_g & 0x0ff) << 8)
	| ((map->ceil_b & 0x0ff));
}
