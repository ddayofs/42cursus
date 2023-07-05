/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:33:53 by donglee2          #+#    #+#             */
/*   Updated: 2023/07/05 20:03:03 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "00libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

typedef	struct s_args
{
	int		idx;
	char	*cmd_path;
	char	**split_cmd;
}t_args;

//path.c
char	*extract_cmd(char *str);
char	*find_path(char **envp);
char	*add_cmd_to_path(char *path, char *cmd);
void	free_all_splits(char **split_path);
char	*find_cmd_path(char *cmd, char **envp);

#endif