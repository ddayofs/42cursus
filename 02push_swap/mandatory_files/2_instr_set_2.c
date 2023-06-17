/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_instr_set_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:26:20 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/15 13:40:31 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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
	write(1, "ra\n", 3);
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
	write(1, "rb\n", 3);
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
	write(1, "rr\n", 3);
	return ;
}