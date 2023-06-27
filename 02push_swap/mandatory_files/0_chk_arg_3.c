/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_chk_arg_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:23:13 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/23 14:27:38 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	print_err(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	chk_arg(char *str, t_list **lst_a)
{
	char	**tmp1;
	char	*tmp2;
	int		i;

	tmp1 = ft_split(str, ' ');
	if (!tmp1)
		exit(1);
	if (!*tmp1)
		print_err();
	i = -1;
	while (tmp1[++i])
	{
		if ((tmp1[i][0] == '-' || tmp1[i][0] == '+') && tmp1[i][1] == 0)
			print_err();
		chk_plus_zero_front(tmp1[i]);
		tmp2 = ft_itoa(ft_atoi(tmp1[i]));
		if (ft_strcmp(tmp1[i], tmp2))
			print_err();
		else
		{
			free(tmp2);
			ft_lstadd_back(lst_a, ft_lstnew(ft_atoi(tmp1[i])));
		}
	}
	free_all(tmp1);
}
