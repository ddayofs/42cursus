/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:04:58 by donglee2          #+#    #+#             */
/*   Updated: 2023/07/06 11:31:18 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	add_file_name_to_args(char *argv[], int argc, t_args *args)
{
	args->infile_name = argv[1];
	args->outfile_name = argv[argc - 1];
}

void	update_cmd_in_args(char *str, t_args *args, char **envp)
{
	char	*extracted;

	extracted = extract_cmd(str);
	args->cmd_path =  find_cmd_path(extracted, envp);
	args->split_cmd = ft_split(str, ' ');
}

void	exec_1st_cmd(char *file_name, int fds[2], t_args *args, char **envp)
{
	int	fd;

	fd = open (file_name, O_RDONLY);
	if (fd == -1)
		exit(1);
	dup2(fd, STDIN_FILENO);
	close (fd);
	close(fds[0]);
	dup2(fds[1], 1);
	close(fds[1]);
	execve(args->cmd_path, args->split_cmd, envp);
	exit(1);
}

void	exec_last_cmd(char *file_name, int fds[2], t_args *args, char **envp)
{
	int	fd;

	close(fds[1]);
	dup2(fds[0], 0); 
	close(fds[0]);
	fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		exit(1);
	dup2(fd, STDOUT_FILENO);
	close (fd);
	execve(args->cmd_path, args->split_cmd, envp);
	exit(1);
}
// void	exec_child_proc(char *str, t_args args, char **envp)
// {
// 	pid_t	pid;

// 	update_cmd_in_args(str, &args, envp);
// 	pid = fork();
// 	if (pid < 0)
// 		exit(1);
// 	if (pid == 0 && idx == 2)
// 		exec_1st_cmd(argv[1], fds, &args, envp);
// 	else if (pid == 0)
// 		exec_last_cmd(argv[argc - 1], fds, &args, envp);
// }

int	main(int argc, char *argv[], char **envp)
{
	// int		status;
	pid_t	pid;
	int		fds[2];
	int		idx;
	t_args	args;

	if (argc != 5)
		return (1);
	if (pipe(fds) == -1)
		exit(1);
	idx = 1;
	while (++idx < 4)
	{
		update_cmd_in_args(argv[idx], &args, envp);
		pid = fork();
		if (pid < 0)
			exit(1);
		if (pid == 0 && idx == 2)
			exec_1st_cmd(argv[1], fds, &args, envp);
		else if (pid == 0)
			exec_last_cmd(argv[argc - 1], fds, &args, envp);
	}
	close(fds[0]);
	close(fds[1]);	
}
