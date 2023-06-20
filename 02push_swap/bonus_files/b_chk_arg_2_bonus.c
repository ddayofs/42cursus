/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_chk_arg_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:13:34 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/20 16:03:07 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "b_push_swap_bonus.h"
#include <stdlib.h>
#include <unistd.h>

void	chk_arg(char *str, t_list **lst_a)
{
	char	**tmp1;
	char	*tmp2;
	int		i;

	tmp1 = ft_split(str, ' ');
	if (!tmp1)
		exit(1);
	if (!*tmp1)
		print_err();
	i = -1;
	while (tmp1[++i])
	{
		if_plus(tmp1[i]);
		tmp2 = ft_itoa(ft_atoi(tmp1[i]));
		if (ft_strcmp(tmp1[i], tmp2))
			print_err();
		else
		{
			free(tmp2);
			ft_lstadd_back(lst_a, ft_lstnew(ft_atoi(tmp1[i])));
		}
	}
	free_all(tmp1);
}

void	print_err(void)
{
	write(2, "Error\n", 6);
	exit(1);
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

void	if_plus(char *str)
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
