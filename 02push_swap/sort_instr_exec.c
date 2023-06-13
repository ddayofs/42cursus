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

int	find_best_in_b(t_info *info, int info_size)
{
	int	i;
	int	min;
	int	best_node;

	min = INT_MAX;
	i = -1;
	while (++i < info_size)
	{
		if (min > (info + i)->instr_cnt && (info + i)->comb != -1)
		{
			min = (info + i)->instr_cnt;
			best_node = i;
		}
	}
	return (best_node);
}

void	instr_exec(t_list **lst_a, t_list **lst_b, t_info *info, int info_size)
{
	int	best_node;

	best_node = find_best_in_b(info, info_size);
	if ((info + best_node)->comb == RRA_RB)
		rra_rb(lst_a, lst_b, info, info_size);
	else if ((info + best_node)->comb == RA_RRB)
		ra_rrb(lst_a, lst_b, info, info_size);
	else if ((info + best_node)->comb == RA_RB)
		ra_rb(lst_a, lst_b, info, info_size);
	else if ((info + best_node)->comb == RRA_RRB)
		rra_rrb(lst_a, lst_b, info, info_size);
	printf("chosen none\n");
}
