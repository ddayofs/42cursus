/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:04:58 by donglee2          #+#    #+#             */
/*   Updated: 2023/07/06 12:18:07 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	// int		status;
	int		fds[2];
	int		idx;
	t_args	args;

	if (argc != 5 || pipe(fds) == -1)
		return (1);
	idx = 1;
	add_file_name_to_args(argv, argc, &args);
	while (++idx < argc - 1)
	{
		exec_child_proc(&args, idx, fds, envp);
	}
	close(fds[0]);
	close(fds[1]);
}
