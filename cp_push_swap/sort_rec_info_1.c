/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rec_info_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:43:26 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/13 20:23:12 by donglee2         ###   ########seoul.kr  */
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

void	info_init(t_info *info, int info_size)
{
	int	i;

	i = -1;
	while (++i < info_size)
	{
		(info + i)->ra_num = -1;
		(info + i)->rb_num = -1;
		(info + i)->rr_num = -1;
		(info + i)->rra_num = -1;
		(info + i)->rrb_num = -1;
		(info + i)->rrr_num = -1;
		(info + i)->comb = -1;
		(info + i)->instr_cnt = -1;
	}
	return ;
}

// //find out ra, rrb, ra, rra  num
// void	rec_info_1(t_list **lst_a, t_list **lst_b, t_info *info)
// {
// 	int		a_idx;
// 	int		b_idx;
// 	t_list	*b_node;
// 	t_list	*a_node;
// 	t_list	*prev_node;

// 	b_idx = -1;
// 	b_node = *lst_b;
// 	printf("rec_info_1_start\n");
// 	while (b_node)
// 	{
// 		(info + b_node->data)->rb_num = ++b_idx;
// 		(info + b_node->data)->rrb_num = ft_lstsize(*lst_b) - b_idx;
// 		a_node = *lst_a;
// 		a_idx = -1;
// 		while (a_node)
// 		{
// 			// make codes below another func 
// 			(info + b_node->data)->ra_num = ++a_idx;
// 			(info + b_node->data)->rra_num = ft_lstsize(*lst_a) - a_idx;
// 			if (a_node != *lst_a)
// 			{
// 				if (a_node->data > b_node->data && prev_node->data < b_node->data)
// 					break ;
// 			}
// 			else
// 			{
// 				if (a_node->data > b_node->data && ft_lstlast(a_node)->data < b_node->data)
// 					break ;
// 			}
// 			// 
// 			prev_node = a_node;
// 			a_node = a_node->next;
// 		}
// 		b_node = b_node->next;
// 	}

// 	printf("record_info_1_complete\n");
// 	return ;
// }

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

	max = INT_MAX;
	while (lst)
	{
		if (lst->data < max)
			max = lst->data;
		lst = lst->next;
	}
	return (max);

}


void	rec_rb_rrb(t_list *lst_b, t_info *tmp_info)
{
	int		b_idx;
	t_list	*b_node;

	b_idx = -1;
	while (lst_b)
	{
		tmp_info->rb_num = ++b_idx;
		tmp_info->rrb_num = ft_lstsize(lst_b) - b_idx;
		lst_b = lst_b->next;
	}
}

void	case1()
{

}

t_info	*case2(t_list *lst_a, t_list *lst_b, t_list *prev, int *a_idx)
{

	(info + lst_b->data)->ra_num = ++a_idx;
	(info + lst_b->data)->rra_num = ft_lstsize(*lst_a) - a_idx;
	if (a_node != *lst_a)
	{
		if (a_node->data > lst_b->data && prev_node->data < lst_b->data)
			break ;
	}
	else
	{
		if (a_node->data > lst_b->data && ft_lstlast(a_node)->data < lst_b->data)
			break ;
	}
	// 
	prev_node = a_node;
}

void	case3()
{
	
}

void	sort_case()
{
	while (a_node)
{
	if ()
		case1();
	else ()
		case2();
	else
		case3();
	prev_node = a_node;
	a_node = a_node->next;
	if (b_node->data < min_data(*lst_a))
		case1();
	else if (min_data(*lst_a) < b_node ->data
		&& b_node->data < max_data(*lst_a))
		case2();
	else
		case3();

}


void	rec_info_1(t_list *lst_a, t_list *lst_b, t_info *info, t_info *tmp_info)
{
	int		a_idx;
	t_list	*a_node;
	t_list	*prev_node;

	rec_rb_rrb(lst_b, tmp_info);
	while (lst_b)
	{
		lst_b = lst_b->next;
	}
}

// find out each number of each instruction set;
void	rec_info_2(t_info *info, int info_size)
{
	int	arr[4];
	int	i;
	int	min;
	int	j;

	printf("rec_info_2 start\n");
	i = -1;
	while (++i < info_size)
	{
		arr[RRA_RB] = (info + i)->rra_num + (info + i)->rb_num;
		arr[RA_RRB] = (info + i)->ra_num + (info + i)->rrb_num;
		arr[RA_RB] = not_smaller_one((info + i)->ra_num, (info + i)->rb_num);
		arr[RRA_RRB] = not_smaller_one((info + i)->rra_num,
				(info + i)->rrb_num);
		// printf("info[%d]:--------------\n", i);
		// for(int k = 0; k < 4; k++)
		// 	printf("arr[%d] = %d\n", k, arr[k]);
		min = INT_MAX;
		j = -1;
		while (++j < 4)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				(info + i)->comb = j;
				(info + i)->instr_cnt = min;
			}
		}
	}
	// for (int i = 0; i < info_size;i++)
	// 	printf("info[%d]:-----------------------\nra == %d\nrb == %d\nrr == %d\nrra == %d\nrrb == %d\nrrr == %d\ncomb == %d\ncnt == %d\n", i, info[i].ra_num, info[i].rb_num, info[i].rr_num, info[i].rra_num, info[i].rrb_num, info[i].rrr_num, info[i].comb, info[i].instr_cnt);
}
