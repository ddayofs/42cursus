/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_ll.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:01:01 by donglee2          #+#    #+#             */
/*   Updated: 2023/05/30 17:06:56 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	bytes_needed(long long nbr, int base_len)
{
	int	cnt;

	cnt = 0;
	if (nbr == 0)
		cnt++;
	else if (nbr < 0)
	{
		cnt++;
		nbr *= -1;
	}
	while (nbr)
	{
		nbr /= base_len;
		cnt++;
	}
	cnt++;
	return (cnt);
}

void	ll_to_str(long long nbr, char *base, int base_len, char *str)
{
	int	null_idx;

	null_idx = bytes_needed(nbr, base_len) - 1;
	str[null_idx] = 0;
	null_idx--;
	if (nbr == 0)
		str[0] = '0';
	else if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr)
	{
		str[null_idx] = base[nbr % base_len];
		nbr /= base_len;
		null_idx--;
	}
	return ;
}

int	ft_putnbr_base_ll(long long nbr, char *base)
{
	char	str[100];
	int		base_len;
	int		idx;

	idx = 0;
	base_len = ft_strlen(base);
	ll_to_str(nbr, base, base_len, str);
	while (str[idx])
	{
		if (write(1, &str[idx], 1) == -1)
			return (-1);
		idx++;
	}
	return (idx);
}