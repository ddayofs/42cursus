/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:10:52 by donglee2          #+#    #+#             */
/*   Updated: 2023/05/30 16:48:40 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int	format_parsing(va_list ap, const char *str)
{
	if (*str == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (*str == 'd')
		return (ft_putnbr_base_ll(va_arg(ap, int), "0123456789"));
	else if (*str == 'x')
		return (ft_putnbr_base_ll(va_arg(ap, unsigned int),
				"0123456789abcdef"));
	return (-1);
}


int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		cnt;
	int		tmp;

	cnt = 0;
	va_start (ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			tmp = format_parsing(ap, str);
		}
		else
			tmp = write(1, str, 1);
		if (tmp == -1)
		{
			cnt = -1;
			break ;
		}
		cnt += tmp;
		str++;
	}
	return (cnt);
}
