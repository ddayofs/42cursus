/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_sort_rec_info_1_src_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:35:32 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/21 13:01:41 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	not_smaller_one(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

void	info_init(t_info *info)
{
	info->ra_num = -1;
	info->rb_num = -1;
	info->rr_num = -1;
	info->rra_num = -1;
	info->rrb_num = -1;
	info->rrr_num = -1;
	info->comb = 777;
	info->cnt = UINT_MAX;
	return ;
}

int	min_data(t_list *lst)
{
	int	min;

	min = INT_MAX;
	while (lst)
	{
		if (lst->data < min)
			min = lst->data;
		lst = lst->next;
	}
	return (min);
}

int	max_data(t_list *lst)
{
	int	max;

	max = INT_MIN;
	while (lst)
	{
		if (max < lst->data)
			max = lst->data;
		lst = lst->next;
	}
	return (max);
}
