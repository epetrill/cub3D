/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbasic3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 07:12:09 by epetrill          #+#    #+#             */
/*   Updated: 2020/10/30 03:08:01 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void		ft_bzero(void *s, size_t n)
{
    size_t        i;
    char        *str;

    i = 0;
    str = s;
    while (i < n)
        str[i++] = 0;
}