/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:22:42 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/15 20:39:46 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	sort_2nodes(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	if (tmp->next->data < tmp->data)
		sa(lst);
	return ;
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
	return ;
}

int	ls_exec_ra_rra(t_list **lst_a, int a_idx)
{
	int	i;

	i = -1;
	if (a_idx <= ft_lstsize(*lst_a) / 2)
	{
		while (++i < a_idx)
			ra(lst_a);
		return (1);
	}
	else
	{
		while (++i < ft_lstsize(*lst_a) - a_idx)
			rra(lst_a);
		return (1);
	}
	return (0);
}

void	last_sort(t_list **lst_a)
{
	t_list	*a_node;
	int		a_idx;
	int		min;

	a_node = *lst_a;
	min = min_data(*lst_a);
	a_idx = -1;
	while (a_node)
	{
		++a_idx;
		if (a_node->data == min)
		{
			if (!ls_exec_ra_rra(lst_a, a_idx))
				break ;
		}
		a_node = a_node->next;
	}
}

void	sort_over_3nodes(t_list **lst_a, t_list **lst_b)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		exit(1);
	make_indexed_lst(lst_a);
	ready_to_greedy(lst_a, lst_b);
	sort_3nodes(lst_a);
	while (*lst_b)
	{
		info_init(info);
		record_info(lst_a, lst_b, info);
		instr_exec(lst_a, lst_b, info);
		pa(lst_a, lst_b);
	}
	free(info);
	info = NULL;
	last_sort(lst_a);
	return ;
}
