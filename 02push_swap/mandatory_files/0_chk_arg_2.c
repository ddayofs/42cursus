/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_chk_arg_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:13:34 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/23 14:16:34 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	chk_plus_front(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+')
	{
		while (str[i])
		{
			str[i] = str[i + 1];
			i++;
		}
	}
	return ;
}

void	chk_zero_front(char *str)
{
	int	i;
	int	cnt;
	int	start;

	cnt = 0;
	i = 0;
	start = 0;
	if (str[i] == '-')
		i++;
	start = i;
	while (str[i] == '0')
	{
		cnt++;
		i++;
	}
	if (str[i] == 0)
	{
		str[0] = '0';
		str[1] = 0;
		return ;
	}
	--start;
	while (str[++start + cnt])
		str[start] = str[start + cnt];
	str[start] = 0;
}

void	chk_plus_zero_front(char *str)
{
	chk_plus_front(str);
	chk_zero_front(str);
}

int	chk_sorted(t_list *lst)
{
	if (!lst)
		return (1);
	while (lst->next)
	{
		if (lst->data > lst->next->data)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	chk_dup(t_list	*lst)
{
	int		integer;
	t_list	*lst_tmp;

	while (lst)
	{
		integer = lst->data;
		lst_tmp = lst->next;
		while (lst_tmp)
		{
			if (integer == lst_tmp->data)
				return (0);
			lst_tmp = lst_tmp->next;
		}
		lst = lst->next;
	}
	return (1);
}
