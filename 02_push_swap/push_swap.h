/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:04:51 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/14 20:19:59 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# define RRA_RB			0
# define RA_RRB			1
# define RA_RB			2
# define RRA_RRB		3
# define INT_MAX		2147483647;
# define INT_MIN		-2147483648;
# define USINT_MAX		4294967295;

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}t_list;

typedef struct s_info
{
	int				ra_num;
	int				rb_num;
	int				rr_num;
	int				rra_num;
	int				rrb_num;
	int				rrr_num;
	int				comb;
	unsigned int	instr_cnt;
}t_info;

//instr_src_1.c
t_list	*ft_lstnew(int integer);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);

//instr_src_2
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

//instr_set_1.c
void	sa(t_list **lst);
void	sb(t_list **lst);
void	pa(t_list **lst_a, t_list **lst_b);
void	pb(t_list **lst_b, t_list **lst_a);

//instr_set_2.c
void	ra(t_list **lst);
void	rb(t_list **lst);
void	rr(t_list **lst_a, t_list **lst_b);

//instr_set_3.c
void	rra(t_list **lst);
void	rrb(t_list **lst);
void	rrr(t_list **lst_a, t_list **lst_b);

//chk_arg_1.c
int		ft_atoi(char *str);
void	chk_arg(char *str, t_list **lst_a);

//chk_arg_2.c
void	print_err(void);
void	if_plus(char c, char *str);
void	chk_dup_sorted(t_list *lst);

//chk_arg_split.c
char	**ft_split(char const *s, char c);

//sort_instr_exec.c
void	rra_rb(t_list **lst_a, t_list **lst_b, t_info *info);
void	ra_rrb(t_list **lst_a, t_list **lst_b, t_info *info);
void	ra_rb(t_list **lst_a, t_list **lst_b, t_info *info);
void	rra_rrb(t_list **lst_a, t_list **lst_b, t_info *info);
void	instr_exec(t_list **lst_a, t_list **lst_b, t_info *info);

//sort_prep.c
void	make_indexed_lst(t_list **lst);
void	ready_to_greedy(t_list **lst_a, t_list **lst_b);

//sort_rec_info_1.c
void	case_1(t_list *lst_a, t_list *lst_b, t_info *info_tmp);
void	case_2(t_list *lst_a, t_info *info_tmp);

//sort_rec_info_2.c
void	rec_info_1(t_list *lst_a, t_list *lst_b, t_info *info);
void	rec_info_2(t_info *info);

//sort_rec_info_3.c
void	ra_rb_case(t_info *info);
void	rra_rrb_case(t_info *info);
void	rec_info_3(t_info *info);
void	record_info(t_list **lst_a, t_list **lst_b, t_info *info);

//sort_rec_info_src.c
int		not_smaller_one(int a, int b);
void	info_init(t_info *info);
int		min_data(t_list *lst);
int		max_data(t_list *lst);

//sort.c
void	ft_sort(int argc, t_list **lst_a, t_list **lst_b);

// void	sort_2nodes(t_list **lst);
void	sort_3nodes(t_list **lst);
void	ft_sort(int argc, t_list **lst_a, t_list **lst_b);

//main.c
void	print(t_list *a, t_list *b);

#endif
