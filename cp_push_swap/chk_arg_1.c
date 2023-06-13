/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_arg_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:48:19 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/06 12:47:19 by donglee2         ###   ########seoul.kr  */
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
	if (ret == 0)
		return (0);
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

void	chk_arg(char *str, t_list **lst_a)
{
	char	**tmp1;
	char	*tmp2;
	int		i;

	tmp1 = ft_split(str, ' ');
	if (!tmp1)
		print_err();
	i = -1;
	while (tmp1[++i])
	{
		if_plus(tmp1[i][0], tmp1[i]);
		tmp2 = ft_itoa(ft_atoi(tmp1[i]));
		if (ft_strcmp(tmp1[i], tmp2))
			print_err();
		else
		{
			free(tmp2);
			tmp2 = NULL;
			ft_lstadd_back(lst_a, ft_lstnew(ft_atoi(tmp1[i])));
		}
	}
}
