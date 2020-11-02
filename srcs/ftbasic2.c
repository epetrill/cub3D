/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbasic2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 07:05:03 by epetrill          #+#    #+#             */
/*   Updated: 2020/10/30 16:17:50 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char		*ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

int			ft_wlen(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

void		ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_freestruct(t_mapinfo *pinfo)
{
	if(pinfo->north)
		free(pinfo->north);
	if(pinfo->south)
		free(pinfo->south);
	if(pinfo->east)
		free(pinfo->east);
	if(pinfo->west)
		free(pinfo->west);
	if(pinfo->sprite)
		free(pinfo->sprite);
	pinfo = NULL;
}
