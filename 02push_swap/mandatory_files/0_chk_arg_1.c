/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_chk_arg_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:48:19 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/17 17:52:30 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	integer;
	int	sign;

	integer = 0;
	sign = 1;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		integer = 10 * integer + (*str - '0');
		str++;
	}
	return (sign * integer);
}

int	how_many_digits(long long nbr, int base_len)
{
	int	count;

	count = 0;
	if (nbr == 0)
		count++;
	else if (nbr < 0)
	{
		count++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr /= base_len;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long long	nbr;
	char		*ret;
	int			ret_len;
	int			i;

	nbr = (long long)n;
	ret_len = how_many_digits(nbr, 10);
	ret = (char *)malloc(sizeof(char) * (ret_len + 1));
	if (!ret)
		exit(1);
	if (nbr == 0)
		ret[0] = '0';
	else if (nbr < 0)
	{
		nbr *= -1;
		ret[0] = '-';
	}
	i = 0;
	while (nbr > 0)
	{
		ret[ret_len - 1 - i++] = nbr % 10 + '0';
		nbr /= 10;
	}
	ret[ret_len] = 0;
	return (ret);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (*ptr1 || *ptr2)
	{
		if (*ptr1 != *ptr2)
			return ((*ptr1 - *ptr2));
		ptr1++;
		ptr2++;
	}
	return (0);
}

void	free_all(char **tmp1)
{
	int	i;

	i = -1;
	while (tmp1[++i])
		free(tmp1[i]);
	free(tmp1);
}
