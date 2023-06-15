/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_sort_prep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:30:41 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/15 20:21:32 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	sort_intarr(int	*arr, int arrsize)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < arrsize - 1)
	{
		j = i + 1;
		while (j < arrsize)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return ;
}

void	ch_int_to_idx(t_list **lst, int *tmp, int lst_size)
{
	int		idx;
	t_list	*cur_node;

	cur_node = *lst;
	idx = -1;
	while (cur_node)
	{
		tmp[++idx] = cur_node->data;
		cur_node = cur_node->next;
	}
	sort_intarr(tmp, lst_size);
	cur_node = *lst;
	while (cur_node)
	{
		idx = -1;
		while (++idx < lst_size)
		{
			if (cur_node->data == tmp[idx])
			{
				cur_node->data = idx;
				break ;
			}
		}	
		cur_node = cur_node->next;
	}
}

void	make_indexed_lst(t_list **lst)
{
	int		*tmp;
	t_list	*cur_node;
	int		lst_size;

	cur_node = *lst;
	lst_size = ft_lstsize(cur_node);
	tmp = (int *)malloc(sizeof(int) * lst_size);
	if (!tmp)
		exit(1);
	ch_int_to_idx(lst, tmp, lst_size);
	free(tmp);
	tmp = NULL;
	return ;
}

void	ready_to_greedy(t_list **lst_a, t_list **lst_b)
{
	t_list	*top;
	int		lst_a_size;
	int		i;

	lst_a_size = ft_lstsize(*lst_a);
	i = -1;
	while (++i < lst_a_size && ft_lstsize(*lst_a) > 3)
	{
		top = *lst_a;
		if (top->data < lst_a_size / 3)
		{
			pb(lst_b, lst_a);
			rb(lst_b);
		}
		else if (top->data < lst_a_size * 2 / 3)
			pb(lst_b, lst_a);
		else
			ra(lst_a);
	}
	while (ft_lstsize(*lst_a) > 3)
		pb(lst_b, lst_a);
	return ;
}
