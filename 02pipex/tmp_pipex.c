/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_pipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:10:22 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/29 19:49:07 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
// for bonus
// int	**make_arr_bonus(int argc, int ***fds)
// {
// 	int	i;

// 	*fds = (int **)malloc(sizeof(int *) * (argc - 3));
// 	if (!*fds)
// 		exit (1);
// 	i = -1;
// 	while (++i <= argc - 3)
// 	{
// 		*fds[i] = (int *)malloc(sizeof(int) * 2);
// 		if (!*fds[i])
// 			exit(1);
// 	}
// 	i = -1;
// 	while (++i <= argc - 3)
// 		pipe(*fds[i]);
// 	return (*fds);
// }

// chk list-> func()
//1. valid instr input by chking whether instr input is in instr dir
//2. valid args num
//3. find out num of args & num of pipes

int	main(int argc, char *argv[], char **envp)
{
	int	pid;
	int	fds[2];
	int	in_fd;
	int	out_fd;

	//before fork
	if (pipe(fds) == -1)
		exit(1);
	//1st fork
	pid = fork();
	if (pid == 0)
	{
		in_fd = open ("file1", O_RDONLY);
		if (in_fd == -1)
			exit(1);
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
		close(fds[0]);
		dup2(fds[1], 1);
		close(fds[1]);
		execve();
	}
	//2nd fork
	pid = fork();
	if (pid == 0)
	{
		dup2(fds[0], 0);
		close(fds[0]);
		out_fd = open ("file2", O_WRONLY | O_CREAT | O_TRUNC);
		if (out_fd == -1)
			exit(1);
		dup2(out_fd, 1);
		close(out_fd);
	}
	close(fds[0]);
	close(fds[1]);
}
