/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:18:53 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/11 20:26:23 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	instr_exec()
{

}

void	sort_over_3nodes(t_list **lst_a, t_list **lst_b)
{
	t_info	*info;
	int		info_size;

	info_size = ft_lstsize(*lst_a);
	make_indexed_lst(lst_a);
	ready_to_greedy(lst_a, lst_b);
	sort_3nodes(lst_a);
	info = (t_info *)malloc(sizeof(t_info) * info_size);
	if (!info)
		exit (1);
	record_info(lst_a, lst_b, &info, info_size);

}
