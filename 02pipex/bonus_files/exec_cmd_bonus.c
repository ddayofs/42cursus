/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:01:08 by donglee2          #+#    #+#             */
/*   Updated: 2023/07/10 21:15:01 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// void	odd_case(t_pipes *pipes, t_args *args, char **envp)
// {
// 	dup2(pipes->fds_1[0], STDIN_FILENO);
// 	close(pipes->fds_1[0]);
// 	dup2(pipes->fds_2[1], STDOUT_FILENO);
// 	close(pipes->fds_2[1]);
// 	update_cmd_in_args(args->idx, args, envp);
// 	execve(args->cmd_path, args->split_cmd, envp);
// 	exit(1);
// }

// void	even_case(t_pipes *pipes, t_args *args, char **envp)
// {
// 	dup2(pipes->fds_2[0], STDIN_FILENO);
// 	close(pipes->fds_2[0]);
// 	dup2(pipes->fds_1[1], STDOUT_FILENO);
// 	close(pipes->fds_1[1]);
// 	update_cmd_in_args(args->idx, args, envp);
// 	execve(args->cmd_path, args->split_cmd, envp);
// 	exit(1);
// }

// void	exec_mid_cmd(int **fds_ptr, t_args *args, char **envp)
// {
// 	if (args->idx % 2 == 1)
// 		odd_case(pipes, args, envp);
// 	else
// 		even_case(pipes, args, envp);
// }

void	exec_1st_cmd(char *file_name, int **fds_ptr, t_args *args, char **envp)
{
	int	fd;

	fd = open (file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("bash: ", STDERR_FILENO);
		perror(file_name);
		exit(1);
	}
	dup2(fd, STDIN_FILENO);
	close (fd);
	close(fds_ptr[0]);
	dup2(fds_ptr[1], STDOUT_FILENO);
	close(fds_ptr[1]);
	update_cmd_in_args(args->idx, args, envp);
	execve(args->cmd_path, args->split_cmd, envp);
	exit(1);
}

void	exec_mid_cmd(int **fds_ptr, int i, t_args *args, char **envp)
{
	dup2(fds_ptr[i][0], STDIN_FILENO);
	close(fds_ptr[i][0]);
	dup2(fds_ptr[1 - i][1], STDOUT_FILENO);
	close(fds_ptr[1 - i][1]);
	update_cmd_in_args(args->idx, args, envp);
	execve(args->cmd_path, args->split_cmd, envp);
	exit(1);
}

void	exec_last_cmd(char *file_name, int **fds_ptr, t_args *args, char **envp)
{
	int	fd;

	close(fds_ptr[1]);
	dup2(fds_ptr[0], STDIN_FILENO); 
	close(fds_ptr[0]);
	fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("bash: ", STDERR_FILENO);
		perror(file_name);
		exit(1);
	}
	dup2(fd, STDOUT_FILENO);
	close (fd);
	update_cmd_in_args(args->idx, args, envp);
	execve(args->cmd_path, args->split_cmd, envp);
	exit(1);
}

pid_t	exec_child_proc(t_args *args, int **fds_ptr, char **envp)
{
	pid_t	pid;
	int		i;

	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid == 0 && args->idx == 2)
		exec_1st_cmd(args->infile_name, fds_ptr, args, envp);
	else if (pid == 0 && args->idx == args->argc - 2)
		exec_last_cmd(args->outfile_name, fds_ptr, args, envp);
	else if (pid == 0)
		exec_mid_cmd(fds_ptr, i, args, envp);
	else
	{
		i = args->idx % 2;
		if (args->idx == 2)
			close(fds_ptr[i][0]);
		close(fds_ptr[1 - i][1]);
		pipe(fds_ptr[i]);
		return (pid);
	}
}
