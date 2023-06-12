/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:22:42 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/12 20:53:52 by donglee2         ###   ########seoul.kr  */
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
}

void	sort_over_3nodes(t_list **lst_a, t_list **lst_b)
{
	t_info	*info;
	int		info_size;

	info_size = ft_lstsize(*lst_a);
	make_indexed_lst(lst_a);
	ready_to_greedy(lst_a, lst_b);
	printf("OK_0\n");
	sort_3nodes(lst_a);
	printf("OK_01\n");
	//delete_print func
	print(*lst_a, *lst_b);
	info = (t_info *)malloc(sizeof(t_info) * info_size);
	if (!info)
		exit (1);
	info_init(info, info_size);
	printf("OK_init\n");
	record_info(lst_a, lst_b, info, info_size);
	instr_exec(lst_a, lst_b, info, info_size);
}

void	ft_sort(int argc, t_list **lst_a, t_list **lst_b)
{
	if (argc == 3)
		sort_2nodes(lst_a);
	else if (argc == 4)
		sort_3nodes(lst_a);
	else
		sort_over_3nodes(lst_a, lst_b);
	exit(1);
}
