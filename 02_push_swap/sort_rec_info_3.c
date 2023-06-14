/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rec_info_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:53:07 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/14 20:14:44 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rb_case(t_info *info)
{
	if (info->ra_num >= info->rb_num)
	{
		info->rr_num = info->rb_num;
		info->ra_num -= info->rr_num;
		info->rb_num = 0;
	}
	else
	{
		info->rr_num = info->ra_num;
		info->rb_num -= info->rr_num;
		info->ra_num = 0;
	}
	info->rra_num = 0;
	info->rrb_num = 0;
	info->rrr_num = 0;
	return ;
}

void	rra_rrb_case(t_info *info)
{
	if (info->rra_num >= info->rrb_num)
	{
		info->rrr_num = info->rrb_num;
		info->rra_num -= info->rrr_num;
		info->rrb_num = 0;
	}
	else
	{
		info->rrr_num = info->rra_num;
		info->rrb_num -= info->rrr_num;
		info->rra_num = 0;
	}
	info->ra_num = 0;
	info->rb_num = 0;
	info->rr_num = 0;
	return ;
}

// revise the num of instr when excuting ra_rb, rra_rrb 
void	rec_info_3(t_info *info)
{
	if (info->comb == RA_RB)
		ra_rb_case(info);
	else if (info->comb == RRA_RRB)
		rra_rrb_case(info);
}

void	record_info(t_list **lst_a, t_list **lst_b, t_info *info)
{
	rec_info_1(*lst_a, *lst_b, info);
	rec_info_3(info);
}

	// printf("after rec_info_3----------------------------------\n");
	// printf("info->ra_num == %d\ninfo->rb_num == %d\ninfo->rr_num == %d\ninfo->rra_num == %d\ninfo-> rrb_num == %d\ninfo->rrr_num == %d\ninfo->comb == %d\ninfo->instr_cnt == %u\n\n", info->ra_num, info->rb_num, info->rr_num, info->rra_num, info->rrb_num, info->rrr_num, info->comb, info->instr_cnt);