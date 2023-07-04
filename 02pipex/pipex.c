/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:04:58 by donglee2          #+#    #+#             */
/*   Updated: 2023/07/04 21:52:35 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//stdin -> file1
void	read_infile(char *str)
{
	int	fd;

	fd = open (str, O_RDONLY);
	if (fd == -1)
		exit(1);
	dup2(fd, STDIN_FILENO);
	close (fd);
}

//stdout -> file2
void	write_outfile(char *str)
{
	int	fd;

	fd = open(str, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		exit(1);
	dup2(fd, STDOUT_FILENO);
	close (fd);
}

int	main(int argc, char *argv[], char **envp)
{
	pid_t	pid;
	int		fds[2];
	int		idx;

	if (argc != 5)
		return (0);
	if (pipe(fds) == -1)
		exit(1);
	idx = 2;
	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid == 0)//child process
	{
		read_infile(argv[1]);
		close(fds[0]);
		dup2(fds[1], 1);
		close(fds[1]);
		execve(find_cmd_path(extract_cmd(argv[idx]), envp), ft_split(argv[idx], ' '), envp);
	}
	else
		idx++;
	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid == 0)//child process
	{
		close(fds[1]);
		dup2(fds[0], 0); 
		close(fds[0]);
		write_outfile(argv[argc - 1]);
		execve(find_cmd_path(extract_cmd(argv[idx]), envp), ft_split(argv[idx], ' '), envp);
	}
	close(fds[0]);
	close(fds[1]);
}

// int	main(int argc, char *argv[], char **envp)
// {
// 	int		pid;
// 	int		fds[2];
// 	int		i;
// 	int		in_fd;
// 	int		out_fd;

// 	if (argc != 5)
// 		return (0);
// 	if (pipe(fds) == -1)
// 		exit(1);
// 	i = 2;
// 	pid = fork();
// 	if (pid == 0)//child process
// 	{
// 		in_fd = open (argv[1], O_RDONLY);
// 		if (in_fd == -1)
// 			exit(1);
// 		dup2(in_fd, STDIN_FILENO);
// 		dup2(fds[0], in_fd);
// 		close(fds[0]);
// 		dup2(fds[1], 1);
// 		close(fds[1]);
// 		execve(find_cmd_path(extract_cmd(argv[i]), envp), ft_split(argv[i], ' '), envp);
// 		close (in_fd);
// 		return (0);
// 	}
// 	else
// 	{
// 		i++;
// 	}
// 	pid = fork();
// 	if (pid == 0)//child process
// 	{
// 		dup2(fds[0], 0);
// 		close(fds[1]);
// 		// write_outfile(argv[argc - 1]);
// 		out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC);
// 		if (out_fd == -1)
// 			exit(1);
// 		dup2(out_fd, STDOUT_FILENO);
// 		execve(find_cmd_path(extract_cmd(argv[i]), envp), ft_split(argv[i], ' '), envp);
// 		close(fds[0]);
// 		close (out_fd);
// 		return (0);
// 	}
// 	close(fds[0]);
// 	close(fds[1]);
// }

// int main(int argc, char *argv[], char **envp)
// {
// 	(void)argc;
// 	printf("%s\n", find_cmd_path(extract_cmd(argv[1]), envp));
// }