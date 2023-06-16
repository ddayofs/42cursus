/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_instr_exec_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:41:41 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/16 17:35:06 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	chk_exec_instr(t_list **lst_a, t_list **lst_b, char	*str)
{
	if (!ft_strcmp(str, "sa\n"))
		sa(lst_a);
	else if (!ft_strcmp(str, "sb\n"))
		sb(lst_b);
	else if (!ft_strcmp(str, "pa\n"))
		pa(lst_a, lst_b);
	else if (!ft_strcmp(str, "pb\n"))
		pb(lst_a, lst_b);
	else if (!ft_strcmp(str, "ra\n"))
		ra(lst_a);
	else if (!ft_strcmp(str, "rb\n"))
		rb(lst_b);
	else if (!ft_strcmp(str, "rr\n"))
		rr(lst_a, lst_b);
	else if (!ft_strcmp(str, "rra\n"))
		rra(lst_a);
	else if (!ft_strcmp(str, "rrb\n"))
		rrb(lst_b);
	else if (!ft_strcmp(str, "rrr\n"))
		rrr(lst_a, lst_b);
	else
		print_err();
}
