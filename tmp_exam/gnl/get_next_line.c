/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:42:33 by donglee2          #+#    #+#             */
/*   Updated: 2023/05/30 15:29:16 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*cut_line(char **save)
{
	char	*sep;
	char	*ret;
	char	*tmp;

	sep = *save;
	while (*sep && *sep != '\n')
		sep++;
	ret = ft_substr(*save, 0, sep - *save + 1);
	if (!ret)
	{
		free(*save);
		*save = NULL;
		return (NULL);
	}
	tmp = ft_substr(*save, sep - *save + 1, ft_strlen(*save));
	free(*save);
	if (!tmp)
	{
		*save = NULL;
		free (ret);
		return (NULL);
	}
	*save = tmp;
	return (ret);
}

int	add_line(char **save, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(*save, buff);
	free(*save);
	*save = NULL;
	if (!tmp)
		return (0);
	*save = tmp;
	return (1);
}

int	read_check(int read_size, char **save)
{
	if (read_size == -1 || (read_size == 0 && **save == 0))
	{
		free(*save);
		*save = NULL;
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*save;
	size_t		read_size;
	char		buff[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save)
		save = ft_strdup("");
	if (!save)
		return (NULL);
	while (!ft_strchr(save, '\n'))
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (!read_check(read_size, &save))
			return (NULL);
		buff[read_size] = '\0';
		if (read_size == 0)
			break ;
		if (!add_line(&save, buff))
			return (NULL);
	}
	return (cut_line(&save));
}
