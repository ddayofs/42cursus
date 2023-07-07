/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:04:58 by donglee2          #+#    #+#             */
/*   Updated: 2023/07/07 19:11:13 by donglee2         ###   ########seoul.kr  */
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
			parent_status = WEXITSTATUS(status);
	}
	exit (parent_status);

}

void	make_2pipes(int ***fds)
{
	int	i;

	*fds = (int **)malloc(sizeof(int *) * 2);
	if (!*fds)
		exit (1);
	i = -1;
	while (++i < 2)
	{
		*fds[i] = (int *)malloc(sizeof(int) * 2);
		if (!*fds[i])
			exit(1);
	}
	i = -1;
	while (++i < 2)
		pipe(*fds[i]);
}

int	main(int argc, char *argv[], char **envp)
{
	int		status;
	int		**fds;
	pid_t	pid;
	t_args	args;

	make_2pipes(&fds);
	if (argc < 5 || pipe(fds) == -1)
		return (1);
	init_args(argv, argc, &args);
	while (++args.idx < argc - 1)
		pid = exec_child_proc(&args, args.idx, fds, envp);
	close(fds[0]);
	close(fds[1]);
	wait_child_proc(pid, argc, &status);
}
