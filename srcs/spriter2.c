/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spriter2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 10:03:58 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 10:05:27 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	sprite_mapper(t_mapinfo *pinfo)
{
	int			i;
	int			j;
	int			max;
	t_sprite	temp;

	i = 0;
	max = 0;
	while (i < pinfo->numsprite - 1)
	{
		max = i;
		j = i + 1;
		while (j < pinfo->numsprite)
		{
			if (pinfo->sprite[j].dist > pinfo->sprite[i].dist)
				max = j;
			j++;
		}
		if (i != max)
		{
			temp = pinfo->sprite[i];
			pinfo->sprite[i] = pinfo->sprite[max];
			pinfo->sprite[max] = temp;
		}
		i++;
	}
}

void	sprite_sorter(t_mapinfo *pinfo)
{
	int i;

	i = 0;
	while (i < pinfo->counter_sprite)
	{
		pinfo->sprite[i].dist = ((pinfo->player.pos_x - pinfo->sprite[i].x) *
			(pinfo->player.pos_x - pinfo->sprite[i].x) +
			((pinfo->player.pos_y - pinfo->sprite[i].y) *
			((pinfo->player.pos_y - pinfo->sprite[i].y))));
		i++;
	}
	sprite_mapper(pinfo);
}