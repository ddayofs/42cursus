/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:14:25 by donglee2          #+#    #+#             */
/*   Updated: 2023/07/04 21:55:18 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// not yet freed : tmp( == split_str[0])
char	*extract_cmd(char *str)
{
	char	**split_str;
	char	*tmp;
	int		i;

	split_str = ft_split(str, ' ');
	if (!split_str)
		exit(1);
	tmp = split_str[0];
	i = 0;
	free_all_splits(split_str);
	return (tmp);
}

char	*find_path(char **envp)
{
	while (*envp)
	{
		if (*(*envp + 1) == 'A' && *(*envp + 2) == 'T')
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

//not yet freed : path
char	*add_cmd_to_path(char *path, char *cmd)
{
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	if (!tmp)
		exit(1);
	free(path);
	path = ft_strjoin(tmp, cmd);
	free (tmp);
	if (!path)
		exit(1);
	return (path);
}

void	free_all_splits(char **split_path)
{
	int	i;

	i = 0;
	while (split_path[++i])
		free(split_path[i]);
	free(split_path);
}

// perror(cmd);//perror 번호. 추가 ?? 에러메시지 추ㅏㄱ 가능?
// zsh: command not found: <user input>
// vs <user input>: No such file or directory
// what about options????
// implementation : error message
char	*find_cmd_path(char *cmd, char **envp)
{
	char	*path;
	char	**split_path;
	int		i;
	char	*ret;

	path = find_path(envp);
	if (!path)
		exit(1);
	split_path = ft_split(path, ':');
	if (!split_path)
		exit (1);
	i = -1;
	while (split_path[++i])
	{
		split_path[i] = add_cmd_to_path(split_path[i], cmd);
		if (access(split_path[i], X_OK) == 0)
		{
			// ret = ft_strdup(split_path[i]);
			ret = split_path[i];
			free_all_splits(split_path);
			return (ret);
		}
	}
	return (NULL);
}