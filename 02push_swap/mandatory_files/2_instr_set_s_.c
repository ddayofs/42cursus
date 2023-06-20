/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_instr_set_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:18:09 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/20 14:47:15 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	s_(t_list **lst)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (ft_lstsize(*lst) < 2)
		return ;
	tmp1 = *lst;
	*lst = (*lst)->next;
	tmp2 = (*lst)->next;
	(*lst)->next = tmp1;
	tmp1->next = tmp2;
	return ;
}

void	sa(t_list **lst)
{
	s_(lst);
	write(1, "sa\n", 3);
	return ;
}

void	sb(t_list **lst)
{
	s_(lst);
	write (1, "sb\n", 3);
	return ;
}
