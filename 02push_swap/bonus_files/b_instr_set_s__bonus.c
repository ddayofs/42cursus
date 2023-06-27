/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_instr_set_s__bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:18:09 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/22 15:46:24 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "b_push_swap_bonus.h"

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
	return ;
}

void	sb(t_list **lst)
{
	s_(lst);
	return ;
}
