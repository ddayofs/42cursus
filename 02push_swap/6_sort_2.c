/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_sort_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 20:41:15 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/16 15:10:38 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
