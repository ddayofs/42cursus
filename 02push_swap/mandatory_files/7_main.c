/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:45:59 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/20 16:12:49 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	static t_list	*lst_a;
	static t_list	*lst_b;
	int				i;

	if (argc < 2)
		return (0);
	i = 0;
	while (argv[++i])
		chk_arg(argv[i], &lst_a);
	if (!chk_dup(lst_a))
		print_err();
	if (!chk_sorted(lst_a))
		exit(0);
	ft_sort(&lst_a, &lst_b);
	return (0);
}
