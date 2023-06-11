/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:59:38 by donglee2          #+#    #+#             */
/*   Updated: 2023/05/30 16:54:23 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr(char *s)
{
	int	i;

	i = -1;
	if (s == NULL)
		return (write(1, "(null)", 6));
	while (s[++i])
	{
		if (write(1, &s[i], 1) == -1)
			return (-1);
	}
	return (i);
}
