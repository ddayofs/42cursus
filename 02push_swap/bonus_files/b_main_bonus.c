/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_main_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:19:36 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/17 18:09:28 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "b_push_swap_bonus.h"
#include "b_get_next_line_bonus.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	static t_list	*lst_a;
	static t_list	*lst_b;
	int				i;
	char			*new_line;

	if (argc < 2)
		return (0);
	i = 0;
	while (argv[++i])
		chk_arg(argv[i], &lst_a);
	if (!chk_dup(lst_a))
		print_err();
	new_line = get_next_line(0);
	while (new_line)
	{
		chk_exec_instr(&lst_a, &lst_b, new_line);
		free(new_line);
		new_line = get_next_line(0);
	}
	free(new_line);
	if (!chk_sorted(lst_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
