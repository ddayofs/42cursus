/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_sort_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 20:41:15 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/20 16:08:00 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	sort_over_3nodes(t_list **lst_a, t_list **lst_b)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		exit(1);
	make_indexed_lst(lst_a);
	ready_to_greedy(lst_a, lst_b);
	sort_3nodes(lst_a);
	while (*lst_b)
	{
		info_init(info);
		record_info(lst_a, lst_b, info);
		instr_exec(lst_a, lst_b, info);
		pa(lst_a, lst_b);
	}
	free(info);
	last_sort(lst_a);
	return ;
}

void	ft_sort(t_list **lst_a, t_list **lst_b)
{
	int	a_size;

	a_size = ft_lstsize(*lst_a);
	if (a_size == 2)
		sort_2nodes(lst_a);
	else if (a_size == 3)
		sort_3nodes(lst_a);
	else
		sort_over_3nodes(lst_a, lst_b);
	return ;
}
