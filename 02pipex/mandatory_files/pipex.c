/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:04:58 by donglee2          #+#    #+#             */
/*   Updated: 2023/07/07 21:02:06 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_child_proc(pid_t last_pid, int argc, int *status)
{
	pid_t	pid;
	int		i;
	int		parent_status;
	
	i = -1;
	parent_status = 0;
	while(++i < argc - 3)
	{
		pid = waitpid(-1, status, 0);//종료되는 순서대로 status가 기록된다. cmd순서가 아니라.
		if (pid == last_pid)//last pid는 마지막 cmd(마지막 fork) childprocess의 pid
			parent_status = WEXITSTATUS(*status);
	}
	exit (parent_status);
}

int	main(int argc, char *argv[], char **envp)
{
	int		status;
	int		fds[2];
	pid_t	pid;
	t_args	args;

	if (argc != 5 || pipe(fds) == -1)
		return (1);
	add_file_name_to_args(argv, argc, &args);
	while (++args.idx < argc - 1)
		pid = exec_child_proc(&args, args.idx, fds, envp);
	close(fds[0]);
	close(fds[1]);
	wait_child_proc(pid, argc, &status);
}
