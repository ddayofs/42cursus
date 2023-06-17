/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_sort_rec_info_2_src.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:16:42 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/16 20:08:07 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_rb_case(t_info *info)
{
	info->ra_num = 0;
	info->rrb_num = 0;
	info->rr_num = 0;
	info->rrr_num = 0;
	return ;
}

void	ra_rrb_case(t_info *info)
{
	info->rra_num = 0;
	info->rb_num = 0;
	info->rr_num = 0;
	info->rrr_num = 0;
	return ;
}

void	ra_rb_case(t_info *info)
{
	if (info->ra_num >= info->rb_num)
	{
		info->rr_num = info->rb_num;
		info->rb_num = 0;
		info->ra_num -= info->rr_num;
	}
	else
	{
		info->rr_num = info->ra_num;
		info->ra_num = 0;
		info->rb_num -= info->rr_num;
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
		info->rrb_num = 0;
		info->rra_num -= info->rrr_num;
	}
	else
	{
		info->rrr_num = info->rra_num;
		info->rra_num = 0;
		info->rrb_num -= info->rrr_num;
	}
	info->ra_num = 0;
	info->rb_num = 0;
	info->rr_num = 0;
	return ;
}
