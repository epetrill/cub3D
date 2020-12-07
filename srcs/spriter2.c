/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spriter2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 10:03:58 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 20:52:58 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	sprite_mapper(t_mapinfo *map)
{
	int			i;
	int			j;
	int			max;
	t_sprite	temp;

	i = 0;
	max = 0;
	while (i < map->numsprite - 1)
	{
		max = i;
		j = i + 1;
		while (j < map->numsprite)
		{
			if (map->sprite[j].dist > map->sprite[i].dist)
				max = j;
			j++;
		}
		if (i != max)
		{
			temp = map->sprite[i];
			map->sprite[i] = map->sprite[max];
			map->sprite[max] = temp;
		}
		i++;
	}
}

void	sprite_sorter(t_mapinfo *map)
{
	int i;

	i = 0;
	while (i < map->counter_sprite)
	{
		map->sprite[i].dist = ((map->player.pos_x - map->sprite[i].x) *
			(map->player.pos_x - map->sprite[i].x) +
			((map->player.pos_y - map->sprite[i].y) *
			((map->player.pos_y - map->sprite[i].y))));
		i++;
	}
	sprite_mapper(map);
}
