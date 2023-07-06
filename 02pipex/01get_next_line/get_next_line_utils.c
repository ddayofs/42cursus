/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:04:18 by donglee2          #+#    #+#             */
/*   Updated: 2023/04/18 16:03:01 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

ssize_t	ft_strchr_idx(char *s, int c)
{
	ssize_t		idx;
	char		ch;

	idx = 0;
	ch = (char)c;
	while (s[idx])
	{
		if (s[idx] == ch)
			return (idx);
		idx++;
	}
	if (ch == '\0')
		return (idx);
	return (-1);
}

ssize_t	ft_strlen(char *str)
{
	ssize_t	cnt;

	cnt = 0;
	while (*str)
	{
		str++;
		cnt++;
	}
	return (cnt);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	char	*tmp_ptr;
	int		sum_len;

	sum_len = ft_strlen(s1) + ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (sum_len + 1));
	if (!ret)
		return (NULL);
	tmp_ptr = ret;
	while (*s1)
		*(tmp_ptr++) = *(s1++);
	while (*s2)
		*(tmp_ptr++) = *(s2++);
	*tmp_ptr = '\0';
	return (ret);
}

char	*ft_strdup(char *src)
{
	char	*return_arr;
	int		src_len;
	int		i;

	i = 0;
	src_len = ft_strlen(src);
	return_arr = (char *)malloc(sizeof(char) * (src_len + 1));
	if (!return_arr)
		return (0);
	while (src[i])
	{
		return_arr[i] = src[i];
		i++;
	}
	return_arr[i] = 0;
	return (return_arr);
}

char	*ft_substr(char *s, ssize_t start, ssize_t len)
{
	char	*substr;
	ssize_t	s_len;
	ssize_t	i;

	s_len = ft_strlen(s);
	if (s_len <= start)
	{
		substr = (char *)malloc(sizeof(char));
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (s_len - start < len)
		len = s_len - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (0);
	i = -1;
	while (++i < len)
		substr[i] = s[start++];
	substr[i] = '\0';
	return (substr);
}
