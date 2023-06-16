/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_sort_rec_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:11:29 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/16 14:00:05 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	rec_info_1(t_list *lst_a, t_list *lst_b, t_info *info)
{
	int		b_idx;
	int		b_size;
	t_info	*tmp;

	tmp = (t_info *)malloc(sizeof(t_info));
	if (!tmp)
		exit(1);
	b_size = ft_lstsize(lst_b);
	b_idx = -1;
	while (lst_b)
	{
		info_init(tmp);
		tmp->rb_num = ++b_idx;
		tmp->rrb_num = b_size - b_idx;
		rec_ra_rra(lst_a, lst_b, tmp);
		rec_comb_cnt(tmp);
		if (info->cnt > tmp->cnt)
			*info = *tmp;
		lst_b = lst_b->next;
	}
	free (tmp);
	tmp = NULL;
	return ;
}

void	rec_info_2(t_info *info)
{
	if (info->comb == RRA_RB)
		rra_rb_case(info);
	else if (info->comb == RA_RRB)
		ra_rrb_case(info);
	else if (info->comb == RA_RB)
		ra_rb_case(info);
	else
		rra_rrb_case(info);
	return ;
}

void	record_info(t_list **lst_a, t_list **lst_b, t_info *info)
{
	rec_info_1(*lst_a, *lst_b, info);
	rec_info_2(info);
	return ;
}
