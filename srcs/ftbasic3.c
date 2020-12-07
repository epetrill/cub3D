/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbasic3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 07:12:09 by epetrill          #+#    #+#             */
/*   Updated: 2020/12/07 02:56:53 by epetrill         ###   ########lyon.fr   */
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

void	ft_startpos(t_mapinfo *pinfo, char c, int i, int j)
{
	pinfo->start_x = i;
	pinfo->start_y = j;
	if (c == 'N')
		pinfo->cardinal = 1;
	else if (c == 'W')
		pinfo->cardinal = 2;
	else if (c == 'E')
		pinfo->cardinal = 4;
	else if (c == 'S')
		pinfo->cardinal = 3;
}