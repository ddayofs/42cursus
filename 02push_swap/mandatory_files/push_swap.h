/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:04:51 by donglee2          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/06/21 13:01:15 by donglee2         ###   ########seoul.kr  */
=======
/*   Updated: 2023/06/23 13:41:19 by donglee2         ###   ########seoul.kr  */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define RRA_RB			0
# define RA_RRB			1
# define RA_RB			2
# define RRA_RRB		3
# define INT_MAX		2147483647
# define INT_MIN		-2147483648
<<<<<<< HEAD
# define UINT_MAX		4294967295
=======
# define USINT_MAX		4294967295

# include <stdio.h>
>>>>>>> master

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
	unsigned int	cnt;
}t_info;

//chk_arg_1.c
int		ft_atoi(char *str);
int		how_many_digits(long long nbr, int base_len);
char	*ft_itoa(int n);
int		ft_strcmp(char *s1, char *s2);
void	free_all(char **tmp1);

//chk_arg_2.c
void	chk_plus_front(char *str);
void	chk_zero_front(char *str);
int		chk_sorted(t_list *lst);
void	chk_plus_zero_front(char *str);
int		chk_dup(t_list	*lst);

//chk_arg_3.c
void	chk_arg(char *str, t_list **lst_a);
void	print_err(void);

//chk_arg_split.c
char	**ft_split(char const *s, char c);

//instr_src_1.c
t_list	*ft_lstnew(int integer);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);

//instr_src_2
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

//instr_set_p.c
void	pa(t_list **lst_a, t_list **lst_b);
void	pb(t_list **lst_b, t_list **lst_a);

//instr_set_r.c
void	ra(t_list **lst);
void	rb(t_list **lst);
void	rr(t_list **lst_a, t_list **lst_b);

//instr_set_rr.c
void	rra(t_list **lst);
void	rrb(t_list **lst);
void	rrr(t_list **lst_a, t_list **lst_b);

//instr_set_s
void	sa(t_list **lst);
void	sb(t_list **lst);

//sort_prep.c
void	make_indexed_lst(t_list **lst);
void	ready_to_greedy(t_list **lst_a, t_list **lst_b);

//sort_rec_info_1_src_1.c
int		not_smaller_one(int a, int b);
void	info_init(t_info *info);
int		min_data(t_list *lst);
int		max_data(t_list *lst);

//sort_rec_info_1_src_2.c
t_list	*rec_case_1(t_list *lst_a, t_info	*info_tmp, int a_idx);
t_list	*case_1(t_list *lst_a, t_list *lst_b, t_info *info_tmp);
void	case_2(t_list *lst_a, t_info *info_tmp);
void	rec_ra_rra(t_list *lst_a, t_list *lst_b, t_info *info_tmp);
void	rec_comb_cnt(t_info *info);

//4_sort_rec_info_2_src.c
void	rra_rb_case(t_info *info);
void	ra_rrb_case(t_info *info);
void	ra_rb_case(t_info *info);
void	rra_rrb_case(t_info *info);

//4_sort_rec_info.c
void	rec_info_1(t_list *lst_a, t_list *lst_b, t_info *info);
void	rec_info_2(t_info *info);
void	record_info(t_list **lst_a, t_list **lst_b, t_info *info);

//sort_instr_exec.c
void	rra_rb_exec(t_list **lst_a, t_list **lst_b, t_info *info);
void	ra_rrb_exec(t_list **lst_a, t_list **lst_b, t_info *info);
void	ra_rb_exec(t_list **lst_a, t_list **lst_b, t_info *info);
void	rra_rrb_exec(t_list **lst_a, t_list **lst_b, t_info *info);
void	instr_exec(t_list **lst_a, t_list **lst_b, t_info *info);

//sort_1.c
void	sort_2nodes(t_list **lst);
void	sort_3nodes(t_list **lst);
void	last_sort(t_list **lst_a);

//sort_2.c
void	sort_over_3nodes(t_list **lst_a, t_list **lst_b);
void	ft_sort(t_list **lst_a, t_list **lst_b);

//main.c
void	print(t_list *a, t_list *b);

#endif
