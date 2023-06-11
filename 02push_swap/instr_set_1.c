/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_set_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:18:09 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/06 12:31:19 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	sa(t_list **lst)
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
	write(1, "sa\n", 3);
}

void	sb(t_list **lst)
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
	write (1, "sb\n", 3);
}

void	pa(t_list **lst_a, t_list **lst_b)
{
	t_list	*orib_1st;

	if (!ft_lstsize(*lst_b))
		return ;
	orib_1st = *lst_b;
	*lst_b = (*lst_b)->next;
	ft_lstadd_front(lst_a, orib_1st);
	write(1, "pa\n", 3);
}

void	pb(t_list **lst_b, t_list **lst_a)
{
	t_list	*oria_1st;

	if (!ft_lstsize(*lst_a))
		return ;
	oria_1st = *lst_a;
	*lst_a = (*lst_a)->next;
	ft_lstadd_front(lst_b, oria_1st);
	write(1, "pb\n", 3);
}
