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
#include <stdlib.h>

void	rec_ra_rra(t_list *lst_a, t_list *lst_b, t_info *info_tmp)
{
	if (min_data(lst_a) < lst_b->data && lst_b->data < max_data(lst_a))
		case_1(lst_a, lst_b, info_tmp);
	else
		case_2(lst_a, info_tmp);
}

//record ra,rra, rb, rrb num
void	rec_info_1(t_list *lst_a, t_list *lst_b, t_info *info)
{
	int		b_idx;
	t_info	*info_tmp;

	info_tmp = (t_info *)malloc(sizeof(t_info));
	if (!info_tmp)
		exit(1);
	// info_init(info_tmp);
	b_idx = -1;
	while (lst_b)
	{
		info_init(info_tmp);
		info_tmp->rb_num = ++b_idx;
		info_tmp->rrb_num = ft_lstsize(lst_b) - b_idx;
		rec_ra_rra(lst_a, lst_b, info_tmp);
		rec_info_2(info_tmp);
		if (info->instr_cnt > info_tmp->instr_cnt)
			*info = *info_tmp;
		lst_b = lst_b->next;
	}
	free (info_tmp);
	info_tmp = NULL;
	return ;
}

// find out each number of each instruction set;
void	rec_info_2(t_info *info)
{
	int	arr[4];
	int	min;
	int	i;


	printf("info->ra_num == %d\ninfo->rb_num == %d\ninfo->rr_num == %d\ninfo->rra_num == %d\ninfo-> rrb_num == %d\ninfo->rrr_num == %d\ninfo->comb == %d\ninfo->instr_cnt == %u\n\n", info->ra_num, info->rb_num, info->rr_num, info->rra_num, info->rrb_num, info->rrr_num, info->comb, info->instr_cnt);

printf("----------------------------------\n");

	arr[RRA_RB] = info->rra_num + info->rb_num;
	arr[RA_RRB]= info->ra_num + info->rrb_num;
	arr[RA_RB] = not_smaller_one(info->ra_num, info->rb_num);
	arr[RRA_RRB] = not_smaller_one(info->rra_num, info->rrb_num);
	min = INT_MAX;
	i = -1;
	while (++i < 4)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			info->comb = i;
			info->instr_cnt = min;
		}
	}
		printf("info->ra_num == %d\ninfo->rb_num == %d\ninfo->rr_num == %d\ninfo->rra_num == %d\ninfo-> rrb_num == %d\ninfo->rrr_num == %d\ninfo->comb == %d\ninfo->instr_cnt == %u\n\n", info->ra_num, info->rb_num, info->rr_num, info->rra_num, info->rrb_num, info->rrr_num, info->comb, info->instr_cnt);
		printf("!!!!!!!!!!!!!!!!!!!!!\n");
}
