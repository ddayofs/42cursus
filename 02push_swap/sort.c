/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:22:42 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/09 16:45:49 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	sort_2nodes(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	if (tmp->data < tmp->next->data)
		sa(lst);
	exit(0);
}

void	sort_3nodes(t_list **lst)
{
	t_list	*no_1;
	t_list	*no_2;
	t_list	*no_3;

	no_1 = *lst;
	no_2 = (*lst)->next;
	no_3 = no_2->next;
	if (no_1->data < no_3->data && no_3->data < no_2->data)
	{
		sa(lst);
		ra(lst);
	}
	else if (no_2->data < no_1->data && no_1->data < no_3->data)
		sa(lst);
	else if (no_3->data < no_1->data && no_1->data < no_2->data)
		rra(lst);
	else if (no_2->data < no_3->data && no_3->data < no_1->data)
		ra(lst);
	else if (no_3->data < no_2->data && no_2->data < no_1->data)
	{
		sa(lst);
		rra(lst);
	}
	exit (0);
}
void	ft_sort(int argc, t_list **lst_a, t_list **lst_b)
{
	if (argc == 3)
		sort_2nodes(lst_a);
	else if (argc == 4)
		sort_3nodes(lst_a);
	else
		sort_over_3nodes(lst_a, lst_b);
}
