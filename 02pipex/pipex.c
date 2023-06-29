/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:04:58 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/29 19:49:07 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	int		pid;
	int		fds[2];
	int		in_fd;
	int		out_fd;
	int		i;

	if (pipe(fds) == -1)
		exit(1);
	in_fd = open ("file1", O_RDONLY);
	if (in_fd == -1)
		exit(1);
	dup2(in_fd, STDIN_FILENO);
	close(in_fd);
	i = -1;
	while (++i < 2)
	{
		pid = fork();
		if (pid == 0)
		{
			dup2(fds[0], 0);
		}
	}
	close(fds[0]);
	close(fds[1]);
}
