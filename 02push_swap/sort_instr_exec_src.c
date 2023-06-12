/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_instr_exec_src.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:18:53 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/12 15:21:34 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_rb(t_list **lst_a, t_list **lst_b, t_info **info, int info_size)
{
	int	best_node;
	int	i;
	int	j;

	best_node = find_best_in_b(info, info_size);
	i = -1;
	j = -1;
	while (++i < info[best_node]->rra_num)
		rra(lst_a);
	while (++j < info[best_node]->rb_num)
		rb(lst_b);
}

void	ra_rrb(t_list **lst_a, t_list **lst_b, t_info **info, int info_size)
{
	int	best_node;
	int	i;
	int	j;

	best_node = find_best_in_b(info, info_size);
	i = -1;
	j = -1;
	while (++i < info[best_node]->ra_num)
		ra(lst_a);
	while (++j < info[best_node]->rrb_num)
		rrb(lst_b);
}

void	ra_rb(t_list **lst_a, t_list **lst_b, t_info **info, int info_size)
{
	int	best_node;
	int	i;
	int	j;
	int	k;

	best_node = find_best_in_b(info, info_size);
	i = -1;
	j = -1;
	k = -1;
	while (++i < info[best_node]->rr_num)
		rr(lst_a, lst_b);
	while (++j < info[best_node]->ra_num)
		ra(lst_a);
	while (++k < info[best_node]->rb_num)
		rb(lst_b);
}

void	rra_rrb(t_list **lst_a, t_list **lst_b, t_info **info, int info_size)
{
	int	best_node;
	int	i;
	int	j;
	int	k;

	best_node = find_best_in_b(info, info_size);
	i = -1;
	j = -1;
	k = -1;
	while (++i < info[best_node]->rr_num)
		rrr(lst_a, lst_b);
	while (++j < info[best_node]->ra_num)
		rra(lst_a);
	while (++k < info[best_node]->rb_num)
		rrb(lst_b);
}
