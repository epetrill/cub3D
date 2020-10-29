/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftbasic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 07:08:17 by epetrill          #+#    #+#             */
/*   Updated: 2020/10/29 07:12:41 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int			ft_nblen(char *str)
{
	int i;

	i = 0;
	while (str[i] > 47 && str[i] < 58)
		i++;
	return (i);
}

int			ft_atoimod(char *str, int choix)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	if (str[i] < 47 || str[i] > 58)
		return (-1);
	while (str[i] > 47 && str[i] < 58)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (choix == 0 && res > 2000)
		res = 2000;
	else if (choix == 0 && res < 500)
		res = 500;
	return (res);
}

char		*ft_strdup(const char *s1)
{
	char	*c_s1;
	char	*start;

	if (!s1)
		return (NULL);
	c_s1 = malloc(ft_strlen(s1) + 1);
	if (!(start = c_s1))
		return (NULL);
	while (*s1)
		*c_s1++ = *s1++;
	*c_s1 = 0;
	return (start);
}

int			ft_strncmp(const char *s1, const char *s2, int n)
{
	if (!n)
		return (0);
	while (n-- > 1 && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int			ft_isparam(char *str) // Savoir si ligne d'info ou ligne map
{
	int i;

	i = 0;
	if ((str[i] == 'R' && str[i + 1] == ' '))
		return (1);
	if ((str[i] == 'C' && str[i + 1] == ' '))
		return (2);
	if ((str[i] == 'F' && str[i + 1] == ' '))
		return (2);
	if ((str[i] == 'S' && str[i + 1] == ' '))
		return (3);
	if ((str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' '))
		return (4);
	if ((str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' '))
		return (5);
	if ((str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' '))
		return (6);
	if ((str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' '))
		return (7);
	return (0);
}
