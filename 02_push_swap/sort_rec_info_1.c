/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rec_info_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:43:26 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/14 16:32:33 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	case_1(t_list *lst_a, t_list *lst_b, t_info *info_tmp)
{
	t_list	*a_node;
	t_list	*prev;
	int		a_idx;

	a_node = lst_a;
	a_idx = -1;
	while (a_node)
	{
		++a_idx;
		if (a_node != lst_a)
		{
			if (prev->data < lst_b->data && lst_b->data < a_node->data)
			{
				info_tmp->ra_num = a_idx;
				info_tmp->rra_num = ft_lstsize(lst_a) - a_idx;
				return ;
			}
		}
		else
		{
			if (ft_lstlast(a_node)->data < lst_b->data && lst_b->data < a_node->data)
			{
				info_tmp->ra_num = a_idx;
				info_tmp->rra_num = ft_lstsize(lst_a) - a_idx;
				return ;
			}
		}
		prev = a_node;
		a_node = a_node->next;
	}
}

void	case_2(t_list *lst_a, t_info *info_tmp)
{
	t_list	*a_node;
	int		a_idx;

	a_node = lst_a;
	a_idx = -1;
	while (a_node)
	{
		++a_idx;
		if (a_node->data == min_data(lst_a))
		{
			info_tmp->ra_num = a_idx;
			info_tmp->rra_num = ft_lstsize(lst_a) - a_idx;
			return ;
		}
		a_node = a_node->next;
	}
}
