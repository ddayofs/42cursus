/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_sort_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 20:41:15 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/15 20:41:33 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(int argc, t_list **lst_a, t_list **lst_b)
{
	if (argc == 3)
		sort_2nodes(lst_a);
	else if (argc == 4)
		sort_3nodes(lst_a);
	else
		sort_over_3nodes(lst_a, lst_b);
	return ;
}
