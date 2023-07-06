/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:04:21 by donglee2          #+#    #+#             */
/*   Updated: 2023/04/18 15:30:46 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 777
# endif

# include <unistd.h>

typedef struct s_list
{
	int				fd_num;
	char			*save;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

ssize_t	ft_strchr_idx(char *s, int c);
ssize_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
char	*ft_substr(char *s, ssize_t start, ssize_t len);

#endif