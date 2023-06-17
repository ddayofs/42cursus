/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_instr_set_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:25:19 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/15 13:40:16 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	rra(t_list **lst)
{
	t_list	*cur_node;
	t_list	*tmp;

	if (ft_lstsize(*lst) < 2)
		return ;
	cur_node = *lst;
	while (cur_node->next->next)
		cur_node = cur_node->next;
	tmp = cur_node->next;
	cur_node->next = NULL;
	tmp->next = *lst;
	*lst = tmp;
	write(1, "rra\n", 4);
	return ;
}

void	rrb(t_list **lst)
{
	t_list	*cur_node;
	t_list	*tmp;

	if (ft_lstsize(*lst) < 2)
		return ;
	cur_node = *lst;
	while (cur_node->next->next)
		cur_node = cur_node->next;
	tmp = cur_node->next;
	cur_node->next = NULL;
	tmp->next = *lst;
	*lst = tmp;
	write(1, "rrb\n", 4);
	return ;
}

void	rrr(t_list **lst_a, t_list **lst_b)
{
	t_list	*cur_node;
	t_list	*tmp;

	if (ft_lstsize(*lst_a) < 2)
		return ;
	if (ft_lstsize(*lst_b) < 2)
		return ;
	cur_node = *lst_a;
	while (cur_node->next->next)
		cur_node = cur_node->next;
	tmp = cur_node->next;
	cur_node->next = NULL;
	tmp->next = *lst_a;
	*lst_a = tmp;
	cur_node = *lst_b;
	while (cur_node->next->next)
		cur_node = cur_node->next;
	tmp = cur_node->next;
	cur_node->next = NULL;
	tmp->next = *lst_b;
	*lst_b = tmp;
	write(1, "rrr\n", 4);
	return ;
}