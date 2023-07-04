/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_pipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:10:22 by donglee2          #+#    #+#             */
/*   Updated: 2023/07/04 17:44:03 by donglee2         ###   ########seoul.kr  */
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

void	pipex(int argc, t_arg arg, char *argv[], char *envp[])
{
	int		fds[2];
	pid_t	pid;
	int		repeat_fork;

	repeat_fork = 0;
	pipe(fds);
	pid = fork();
	while (repeat_fork < argc - 3)
	{
		if (repeat_fork != 0 && pid != 0)
			pid = fork();
		if (pid == 0)
		{
			if (pid == 0 && repeat_fork == 0)
			{ 
				arg.infile = open(argv[1], O_RDONLY);
				dup2(arg.infile, STDIN_FILENO);
				dup2(fds[0], arg.infile);
				close(fds[0]);
				dup2(fds[1], STDOUT_FILENO);
				close(fds[1]);
				if (execve(arg.valid_cmd_1, arg.command_1, envp) < 0)
				{
					// perror("NULL");
					ft_putstr_fd("bash: command not found\n", 2);
					exit(127);
				}
				close(arg.infile);
			}
				// first_child(arg, fds, argv, envp);
			else if (pid == 0 && repeat_fork == 1)
			{
				close(fds[1]);
				arg.outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
				dup2(arg.outfile, STDOUT_FILENO);
				if (execve(arg.valid_cmd_2, arg.command_2, envp) < 0)
				{
					// perror("NULL");
					ft_putstr_fd("bash: command not found\n", 2);
					exit(127);
				}
				close(fds[0]);
				close(arg.outfile);
			}
				// last_child(arg, fds, argv, envp);
		}
		else
		{
			dup2(fds[0], STDIN_FILENO);
			repeat_fork++;
		}
	}
	close(fds[0]);
	close(fds[1]);
	int count = 0;
	int status;
	while (pid != 0 && count < 2)
	{
		if (pid == waitpid(-1, &status, 0))
			exit(WEXITSTATUS(status));
		count++;
	}
}