/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_instr_set_r_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:26:20 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/20 15:24:35 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

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
	write(1, "ra\n", 3);
	return ;
}

void	rb(t_list **lst)
{
	r_(lst);
	write(1, "rb\n", 3);
	return ;
}

void	rr(t_list **lst_a, t_list **lst_b)
{
	r_(lst_a);
	r_(lst_b);
	write(1, "rr\n", 3);
	return ;
}
