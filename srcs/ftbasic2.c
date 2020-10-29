/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbasic2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 07:05:03 by epetrill          #+#    #+#             */
/*   Updated: 2020/10/29 07:07:42 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int			ft_strcpymod(char *dst, char *src)
{
	if (!(src && dst))
		return (-1);
	while (*src && *src != ' ')
		*dst++ = *src++;
	*dst = 0;
	return (0);
}

int			ft_wlen(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

void		ft_affstruct(t_mapinfo *info)//PRINTF
{
	printf("Resolution : %d x %d\n", info->res[0], info->res[1]);
	printf("North : %s\n", info->north);
	printf("South : %s\n", info->south);
	printf("East : %s\n", info->east);
	printf("West : %s\n", info->west);
	printf("Sprite : %s\n", info->sprite);
	printf("Floor : %d %d %d\n", info->floor[0], info->floor[1], info->floor[2]);
	printf("Ceiling : %d %d %d\n", info->ceil[0], info->ceil[1], info->ceil[2]);
}

void		ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

t_mapinfo	*ft_freestruct(t_mapinfo *pinfo)
{
	free(pinfo->res);
	free(pinfo->north);
	free(pinfo->south);
	free(pinfo->east);
	free(pinfo->west);
	free(pinfo->sprite);
	free(pinfo->floor);
	free(pinfo->ceil);
	free(pinfo);
	pinfo = NULL;
	return (pinfo);
}
