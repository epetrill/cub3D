/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 07:13:23 by epetrill          #+#    #+#             */
/*   Updated: 2020/10/29 07:13:30 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_strjoin_mod(char *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s1[i])
		i++;
	while (s2[j++])
		i++;
	if (!(ptr = malloc(sizeof(*ptr) * (i + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}

int		ft_strchr_mod(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
