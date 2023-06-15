/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_chk_arg_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:13:34 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/15 20:56:24 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	print_err(void)
{
	write(2, "Error!!!!\n", 11);
	exit(1);
}

void	chk_sorted(t_list *lst)
{
	while (lst->next)
	{
		if (lst->data > lst->next->data)
			return ;
		lst = lst->next;
	}
	exit(0);
}

void	if_plus(char c, char *str)
{
	int	i;

	i = 0;
	if (c == '+')
	{
		while (str[i])
		{
			str[i] = str[i + 1];
			i++;
		}
	}
	return ;
}

void	chk_dup(t_list	*lst)
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
				print_err();
			lst_tmp = lst_tmp->next;
		}
		lst = lst->next;
	}
	return ;
}

void	chk_dup_sorted(t_list *lst)
{
	chk_dup(lst);
	chk_sorted(lst);
	return ;
}
