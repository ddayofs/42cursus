/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_instr_set_r__bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:26:20 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/20 15:30:27 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "b_push_swap_bonus.h"
#include <stdlib.h>

void	r_(t_list **lst)
{
	t_list	*tmp;

	if (ft_lstsize(*lst) < 2)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	ft_lstadd_back(lst, tmp);
	tmp->next = NULL;
}

void	ra(t_list **lst)
{
	r_(lst);
	return ;
}

void	rb(t_list **lst)
{
	r_(lst);
	return ;
}

void	rr(t_list **lst_a, t_list **lst_b)
{
	r_(lst_a);
	r_(lst_b);
	return ;
}
