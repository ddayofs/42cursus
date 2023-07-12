/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:04:58 by donglee2          #+#    #+#             */
/*   Updated: 2023/07/12 12:12:24 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	wait_child_proc(pid_t last_pid, int argc, int *status)
{
	pid_t	pid;
	int		i;
	int		parent_status;

	i = -1;
	while(++i < argc - 3)
	{
		pid = waitpid(-1, status, 0);
		if (pid == last_pid)
			parent_status = WEXITSTATUS(*status);
	}
	exit (parent_status);
}

// not freed yet
void	make_2arrs(int ***fds_ptr_ptr)
{
	int	i;

	*fds_ptr_ptr = (int **)malloc(sizeof(int *) * 2);
	if (!*fds_ptr_ptr)
		exit(1);
	i = -1;
	while (++i < 2)
	{
		*(*fds_ptr_ptr + i) = (int *)malloc(sizeof(int) * 2);
		if (!(*fds_ptr_ptr)[i])
			exit(1);
	}
}

int	main(int argc, char *argv[], char **envp)
{
	int		status;
	int		**fds_ptr;
	pid_t	pid;
	t_args	args;

	if (argc < 5)
		return (1);
	make_2arrs(&fds_ptr);
	if (pipe(fds_ptr[0]) == -1)
		return (1);
	init_args(argv, argc, &args);
	while (++args.idx < argc - 1)
		pid = exec_child_proc(&args, fds_ptr, envp);
	wait_child_proc(pid, argc, &status);
}
