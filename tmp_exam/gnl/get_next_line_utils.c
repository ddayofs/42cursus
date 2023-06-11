/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:48:07 by donglee2          #+#    #+#             */
/*   Updated: 2023/05/30 13:19:52 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

ssize_t	ft_strlen(char *s)
{
	ssize_t	cnt;

	cnt = 0;
	while (*s)
	{
		cnt++;
		s++;
	}
	return (cnt);
}

char	*ft_strdup(char *src)
{
	char	*ret;
	char	*tmp;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!ret)
		return (0);
	tmp = ret;
	while (*src)
		*tmp++ = *src++;
	*tmp = 0;
	return (ret);
}

char	*ft_strchr(char *s, int c)
{
	char	*tmp;

	tmp = (char *)s;
	while (*tmp)
	{
		if (*tmp == (char)c)
			return (tmp);
		tmp++;
	}
	if ((char)c == 0)
		return (tmp);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		sum;
	char	*ret;
	char	*tmp;

	sum = ft_strlen(s1) + ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (sum + 1));
	if (!ret)
		return (0);
	tmp = ret;
	while (*s1)
		*tmp++ = *s1++;
	while (*s2)
		*tmp++ = *s2++;
	*tmp = 0;
	return (ret);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*ret;
	char			*tmp;
	unsigned int	s_len;

	s_len = ft_strlen(s);
	if (s_len <= start)
	{
		ret = (char *)malloc(sizeof(char));
		if (!ret)
			return (NULL);
		ret[0] = 0;
		return (ret);
	}
	if (s_len - start < len)
		len = (s_len - 1) - (start - 1);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	tmp = ret;
	while (len--)
		*tmp++ = s[start++];
	*tmp = 0;
	return (ret);
}
