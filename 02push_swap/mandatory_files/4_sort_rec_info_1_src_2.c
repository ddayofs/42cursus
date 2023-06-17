/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_sort_rec_info_1_src_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:43:26 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/16 15:56:38 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_list	*rec_case_1(t_list *lst_a, t_info *tmp, int a_idx)
{
	tmp->ra_num = a_idx;
	tmp->rra_num = ft_lstsize(lst_a) - a_idx;
	return (NULL);
}

t_list	*case_1(t_list *lst_a, t_list *lst_b, t_info *tmp)
{
	t_list	*a_node;
	t_list	*prev;
	int		a_idx;

	a_node = lst_a;
	a_idx = -1;
	prev = NULL;
	while (a_node)
	{
		++a_idx;
		if (a_node != lst_a)
		{
			if (prev->data < lst_b->data && lst_b->data < a_node->data)
				return (rec_case_1(lst_a, tmp, a_idx));
		}
		else
		{
			if (ft_lstlast(a_node)->data < lst_b->data
				&& lst_b->data < a_node->data)
				return (rec_case_1(lst_a, tmp, a_idx));
		}
		prev = a_node;
		a_node = a_node->next;
	}
	return (NULL);
}

void	case_2(t_list *lst_a, t_info *tmp)
{
	t_list	*a_node;
	int		a_idx;

	a_node = lst_a;
	a_idx = -1;
	while (a_node)
	{
		++a_idx;
		if (a_node->data == min_data(lst_a))
		{
			tmp->ra_num = a_idx;
			tmp->rra_num = ft_lstsize(lst_a) - a_idx;
			return ;
		}
		a_node = a_node->next;
	}
	return ;
}

void	rec_ra_rra(t_list *lst_a, t_list *lst_b, t_info *tmp)
{
	if (min_data(lst_a) < lst_b->data && lst_b->data < max_data(lst_a))
		case_1(lst_a, lst_b, tmp);
	else
		case_2(lst_a, tmp);
}

// find out each number of each instruction set;
void	rec_comb_cnt(t_info *tmp)
{
	int	arr[4];
	int	min;
	int	i;

	arr[RRA_RB] = tmp->rra_num + tmp->rb_num;
	arr[RA_RRB] = tmp->ra_num + tmp->rrb_num;
	arr[RA_RB] = not_smaller_one(tmp->ra_num, tmp->rb_num);
	arr[RRA_RRB] = not_smaller_one(tmp->rra_num, tmp->rrb_num);
	min = INT_MAX;
	i = -1;
	while (++i < 4)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			tmp->comb = i;
			tmp->cnt = min;
		}
	}
	return ;
}
