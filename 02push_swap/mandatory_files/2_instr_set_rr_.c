/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_instr_set_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:25:19 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/20 14:51:06 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	rr_(t_list **lst)
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
}

void	rra(t_list **lst)
{
	rr_(lst);
	write(1, "rra\n", 4);
	return ;
}

void	rrb(t_list **lst)
{
	rr_(lst);
	write(1, "rrb\n", 4);
	return ;
}

void	rrr(t_list **lst_a, t_list **lst_b)
{
	rr_(lst_a);
	rr_(lst_b);
	write(1, "rrr\n", 4);
	return ;
}
