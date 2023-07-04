/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:11:54 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/16 17:17:00 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*cut_line(char **save)
{
	char	*ret_line;
	char	*tmp;
	ssize_t	idx;

	idx = ft_strchr_idx(*save, '\n');
	if (idx == -1)
		idx = ft_strchr_idx(*save, '\0');
	ret_line = ft_substr(*save, 0, idx + 1);
	if (!ret_line)
	{
		free(*save);
		*save = NULL;
		return (NULL);
	}
	tmp = ft_substr(*save, idx + 1, ft_strlen(*save));
	free (*save);
	if (!tmp)
	{
		*save = NULL;
		free (ret_line);
		return (NULL);
	}
	*save = tmp;
	return (ret_line);
}

int	add_line(char **save, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(*save, buff);
	free (*save);
	*save = NULL;
	if (!tmp)
		return (1);
	*save = tmp;
	return (0);
}

int	read_chk(int read_size, char **save)
{
	if (read_size == -1 || (read_size == 0 && !(**save)))
	{
		free(*save);
		*save = NULL;
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*save;
	int				read_size;

	if (!save)
		save = ft_strdup("");
	if (!save)
		return (NULL);
	while (ft_strchr_idx(save, '\n') < 0)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_chk(read_size, &save))
			return (NULL);
		buff[read_size] = '\0';
		if (read_size == 0)
			break ;
		if (add_line(&save, buff))
			return (NULL);
	}
	return (cut_line(&save));
}

// #include <fcntl.h>
// #include <stdio.h>

// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);

// 	char *new_line = get_next_line(fd);
// 	while (new_line)
// 	{
// 		printf("%s", new_line);
// 		new_line = get_next_line(fd);
// 	}
// 	printf("%s\n", new_line);
// 	return (0);
// }