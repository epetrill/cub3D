/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 07:13:12 by epetrill          #+#    #+#             */
/*   Updated: 2020/10/30 16:07:57 by epetrill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int			ft_read(int fd, char **res, char *buffer)
{
	int	i;
	int	j;
	int	ret;

	j = 0;
	ret = 1;
	while (((i = ft_strchr_mod(*res)) == -1) && ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
		if ((*res = ft_strjoin_mod(*res, buffer)) == NULL)
			return (-1);
	}
	i != -1 ? (*res)[i] = '\0' : 0;
	if (ret > 0 && i != -1)
	{
		i = ft_strchr_mod(buffer);
		while (buffer[i])
			buffer[j++] = buffer[1 + i++];
		buffer[j] = '\0';
	}
	return (ret);
}

int			ft_rest(char *res, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	res[i] = '\0';
	while (i-- > 0)
		res[i] = buffer[i];
	i = ft_strchr_mod(buffer);
	if (i != -1)
	{
		buffer[i] == '\n' ? i++ : 0;
		while (buffer[i])
			buffer[j++] = buffer[i++];
		buffer[j] = '\0';
		return (1);
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*buffer;
	char		*res;
	int			ret;

	ret = 1;
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) || !(line)
		|| !(res = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	res[0] = '\0';
	if (!(buffer))
	{
		if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
		ret = ft_read(fd, &res, buffer);
	}
	else
		ft_rest(res, buffer) == 0 ? ret = ft_read(fd, &res, buffer) : 0;
	*line = res;
	if (ret > 0)
		return (1);
	free(buffer);
	buffer = NULL;
	if (ret == 0)
		return (0);
	return (-1);
}

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
