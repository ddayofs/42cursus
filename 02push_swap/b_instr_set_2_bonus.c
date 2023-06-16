/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_instr_set_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:26:20 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/16 17:19:19 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <unistd.h>

void	ra(t_list **lst)
{
	t_list	*tmp;

	if (ft_lstsize(*lst) < 2)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	ft_lstadd_back(lst, tmp);
	tmp->next = NULL;
	return ;
}

void	rb(t_list **lst)
{
	t_list	*tmp;

	if (ft_lstsize(*lst) < 2)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	ft_lstadd_back(lst, tmp);
	tmp->next = NULL;
	return ;
}

void	rr(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;

	if (ft_lstsize(*lst_a) < 2)
		return ;
	if (ft_lstsize(*lst_b) < 2)
		return ;
	tmp = *lst_a;
	*lst_a = (*lst_a)->next;
	ft_lstadd_back(lst_a, tmp);
	tmp->next = NULL;
	tmp = *lst_b;
	*lst_b = (*lst_b)->next;
	ft_lstadd_back(lst_b, tmp);
	tmp->next = NULL;
	return ;
}
