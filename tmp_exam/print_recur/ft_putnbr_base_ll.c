/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_ll.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:01:01 by donglee2          #+#    #+#             */
/*   Updated: 2023/05/30 17:26:07 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base_ll(long long nbr, char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	if (nbr == 0)
	{
		write(1, "0", 1);
	}
	ft_putnbr_base_ll(nbr / i, base);
	write(1, &base[nbr % i], 1);
}

int	main(void)
{
	ft_putnbr_base_ll(0, "0123456789");
}