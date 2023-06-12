/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rec_info_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:43:26 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/12 14:46:57 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	not_smaller_one(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

void	comb_init(t_info **info, int info_size)
{
	int	i;

	i = -1;
	while (++i < info_size)
		info[i]->comb = -1;
}

//find out ra, rrb, ra, rra  num
void	rec_info_1(t_list **lst_a, t_list **lst_b, t_info **info)
{
	int		a_idx;
	int		b_idx;
	t_list	*b_node;
	t_list	*a_node;
	t_list	*prev_node;

	b_idx = -1;
	b_node = *lst_b;
	while (b_node)
	{
		info[b_node->data]->rb_num = ++b_idx;
		info[b_node->data]->rrb_num = ft_lstsize(*lst_b) - b_idx;
		a_node = *lst_a;
		a_idx = -1;
		while (a_node)
		{
			// make codes below another func 
			info[b_node->data]->ra_num = ++a_idx;
			info[b_node->data]->rra_num = ft_lstsize(*lst_a) - a_idx;
			if (a_node != *lst_a)
			{
				if (a_node->data > b_node->data && prev_node->data < b_node->data)
					break ;
			}
			else
			{
				if (a_node->data > b_node->data && ft_lstlast(a_node)->data < b_node->data)
					break ;
			}
			// 
			prev_node = a_node;
			a_node = a_node->next;
		}
		b_node = b_node->next;
	}
}

// find out the number of each instruction set;
void	rec_info_2(t_info **info, int info_size)
{
	int	arr[4];
	int	i;
	int	min;

	i = -1;
	while (++i < info_size)
	{
		arr[RRA_RB] = info[i]->rra_num + info[i]->rb_num;
		arr[RA_RRB] = info[i]->ra_num + info[i]->rrb_num;
		arr[RA_RB] = not_smaller_one(info[i]->ra_num, info[i]->rb_num);
		arr[RRA_RRB] = not_smaller_one(info[i]->rra_num, info[i]->rrb_num);
		min = INT_MAX;
		i = -1;
		while (++i < 4)
		{
			if (arr[i] < min)
			{
				min = arr[i];
				info[i]->comb = i;
				info[i]->instr_cnt = min;
			}
		}
	}
}
