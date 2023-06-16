/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_chk_arg_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:13:34 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/16 19:35:33 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "b_push_swap_bonus.h"
#include <stdlib.h>
#include <unistd.h>

void	print_err(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	chk_sorted(t_list *lst)
{
	while (lst->next)
	{
		if (lst->data > lst->next->data)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	if_plus(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+')
	{
		while (str[i])
		{
			str[i] = str[i + 1];
			i++;
		}
	}
	return ;
}

int	chk_dup(t_list	*lst)
{
	int		integer;
	t_list	*lst_tmp;

	while (lst)
	{
		integer = lst->data;
		lst_tmp = lst->next;
		while (lst_tmp)
		{
			if (integer == lst_tmp->data)
				return (0);
			lst_tmp = lst_tmp->next;
		}
		lst = lst->next;
	}
	return (1);
}
