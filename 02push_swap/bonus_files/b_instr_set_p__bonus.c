/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_instr_set_p__bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:48:59 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/20 15:31:16 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "b_push_swap_bonus.h"

void	p_(t_list **lst_a, t_list **lst_b)
{
	t_list	*orib_1st;

	if (!ft_lstsize(*lst_b))
		return ;
	orib_1st = *lst_b;
	*lst_b = (*lst_b)->next;
	ft_lstadd_front(lst_a, orib_1st);
	return ;
}

void	pa(t_list **lst_a, t_list **lst_b)
{
	p_(lst_a, lst_b);
	return ;
}

void	pb(t_list **lst_b, t_list **lst_a)
{
	p_(lst_b, lst_a);
	return ;
}
