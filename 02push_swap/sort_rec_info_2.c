/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_prep_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:21:32 by marvin            #+#    #+#             */
/*   Updated: 2023/06/11 20:21:32 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rb_case(t_info **info, int idx)
{
	if (info[idx]->ra_num >= info[idx]->rb_num)
	{
		info[idx]->rr_num = info[idx]->rb_num;
		info[idx]->ra_num -= info[idx]->rr_num;
		info[idx]->rb_num = 0;
	}
	else
	{
		info[idx]->rr_num = info[idx]->ra_num;
		info[idx]->rb_num -= info[idx]->rr_num;
		info[idx]->ra_num = 0;
	}
}

void	rra_rrb_case(t_info **info, int idx)
{
	if (info[idx]->rra_num >= info[idx]->rrb_num)
	{
		info[idx]->rrr_num = info[idx]->rrb_num;
		info[idx]->rra_num -= info[idx]->rrr_num;
		info[idx]->rrb_num = 0;
	}
	else
	{
		info[idx]->rrr_num = info[idx]->rra_num;
		info[idx]->rrb_num -= info[idx]->rrr_num;
		info[idx]->rra_num = 0;
	}
}

// revise the num of instr when excuting ra_rb, rra_rrb 
void	rec_info_3(t_info **info, int info_size)
{
	int	idx;

	idx = -1;
	while (++idx < info_size)
	{
		if (info[idx]->comb == RA_RB)
			ra_rb_case(info, idx);
		else if (info[idx]->comb == RRA_RRB)
			rra_rrb_case(info, idx);
	}
}

void	record_info(t_list **lst_a, t_list **lst_b,
		t_info **info, int info_size)
{
	rec_info_1(lst_a, lst_b, info);
	rec_info_2(info, info_size);
	rec_info_3(info, info_size);
}
