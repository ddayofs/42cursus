/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:45:59 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/09 16:23:45 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	print(t_list *a, t_list *b)
{
	printf("a: ");
	while (a)
	{
		printf("[%d]", a->data);
		a = a->next;
	}
	printf("\n");
	printf("b: ");
	while (b)
	{
		printf("[%d]", b->data);
		b = b->next;
	}
	printf("\n");
}

int	main(int argc, char *argv[])
{
	static t_list	*lst_a;
	static t_list	*lst_b;
	int				i;

	if (argc < 3)
		return (0);
	i = 0;
	while (argv[++i])
		chk_arg(argv[i], &lst_a);
	chk_dup_sorted(lst_a);
	make_indexed_lst(&lst_a);
	print(lst_a, lst_b);
	ready_to_greedy(&lst_a, &lst_b);
	print(lst_a, lst_b);
		// ft_sort(argc, &lst_a, &lst_b);
	return (0);
}

// int	main(int argc, char *argv[])
// {
// 	static t_list	*lst_a;
// 	static t_list	*lst_b;
// 	int				i;

// 	if (argc < 3)
// 		return (0);
// 	i = 0;
// 	while (argv[++i])
// 		chk_arg(argv[i], &lst_a);
// 	chk_dup_sorted(lst_a);
// 	print(lst_a, lst_b);
// 	sa(&lst_a);
// 	print(lst_a, lst_b);
// 	pb(&lst_b, &lst_a);
// 	print(lst_a, lst_b);
// 	pb(&lst_b, &lst_a);
// 	print(lst_a, lst_b);
// 	sb(&lst_b);
// 	print(lst_a, lst_b);
// 	pb(&lst_b, &lst_a);
// 	print(lst_a, lst_b);
// 	pb(&lst_b, &lst_a);
// 	print(lst_a, lst_b);
// 	pa(&lst_a, &lst_b);
// 	print(lst_a, lst_b);
// 	ra(&lst_a);
// 	print(lst_a, lst_b);
// 	rb(&lst_b);
// 	print(lst_a, lst_b);
// 	rr(&lst_a, &lst_b);
// 	print(lst_a, lst_b);
// 	rra(&lst_a);
// 	print(lst_a, lst_b);
// 	rrb(&lst_b);
// 	print(lst_a, lst_b);
// 	rrr(&lst_a, &lst_b);
// 	print(lst_a, lst_b);

// 	return (0);
// }
