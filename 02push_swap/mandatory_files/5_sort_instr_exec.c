/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_instr_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:25:11 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/12 14:25:11 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_rb_exec(t_list **lst_a, t_list **lst_b, t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->rra_num)
		rra(lst_a);
	i = -1;
	while (++i < info->rb_num)
		rb(lst_b);
}

void	ra_rrb_exec(t_list **lst_a, t_list **lst_b, t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->ra_num)
		ra(lst_a);
	i = -1;
	while (++i < info->rrb_num)
		rrb(lst_b);
}

void	ra_rb_exec(t_list **lst_a, t_list **lst_b, t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->rr_num)
		rr(lst_a, lst_b);
	i = -1;
	while (++i < info->ra_num)
		ra(lst_a);
	i = -1;
	while (++i < info->rb_num)
		rb(lst_b);
}

void	rra_rrb_exec(t_list **lst_a, t_list **lst_b, t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->rrr_num)
		rrr(lst_a, lst_b);
	i = -1;
	while (++i < info->rra_num)
		rra(lst_a);
	i = -1;
	while (++i < info->rrb_num)
		rrb(lst_b);
}

void	instr_exec(t_list **lst_a, t_list **lst_b, t_info *info)
{
	if (info->comb == RRA_RB)
		rra_rb_exec(lst_a, lst_b, info);
	else if (info->comb == RA_RRB)
		ra_rrb_exec(lst_a, lst_b, info);
	else if (info->comb == RA_RB)
		ra_rb_exec(lst_a, lst_b, info);
	else
		rra_rrb_exec(lst_a, lst_b, info);
	return ;
}
