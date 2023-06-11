/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:04:51 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/10 19:10:12 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# define RRA_RB		0
# define RA_RRB		1
# define RA_RB		2
# define RRA_RRB	3
# define INT_MAX		2147483647;

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}t_list;

typedef struct s_info
{
	int	ra_num;
	int	rb_num;
	int	rr_num;
	int	rra_num;
	int	rrb_num;
	int	rrr_num;
	int	comb;
	int	instr_cnt;
}t_info;

t_list	*ft_lstnew(int integer);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_delnode(t_list *lst);
int		ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

void	sa(t_list **lst);
void	sb(t_list **lst);
void	pa(t_list **lst_a, t_list **lst_b);
void	pb(t_list **lst_b, t_list **lst_a);

void	ra(t_list **lst);
void	rb(t_list **lst);
void	rr(t_list **lst_a, t_list **lst_b);

void	rra(t_list **lst);
void	rrb(t_list **lst);
void	rrr(t_list **lst_a, t_list **lst_b);

int		ft_atoi(char *str);
// int		how_many_digits(long long nbr, int base_len);
// char	*ft_itoa(int n);
// int		ft_strcmp(char *s1, char *s2);
void	chk_arg(char *str, t_list **lst_a);

// int		words_count(char const *str, char c);
// char	*copy_str(char const *str, char c, int *s_idx);
// char	**ft_freeall(char **ret_str);
char	**ft_split(char const *s, char c);

void	print_err(void);
void	if_plus(char c, char *str);
// void	chk_sorted(t_list *lst);
// void	chk_dup(t_list	*lst);
void	chk_dup_sorted(t_list *lst);

// void	sort_2nodes(t_list **lst);
void	sort_3nodes(t_list **lst);
void	ft_sort(int argc, t_list **lst_a, t_list **lst_b);

// void	sort_intarr(int	*arr, int arrsize)
// void	ch_int_to_idx(t_list **lst, int *tmp, int lst_size)
void	make_indexed_lst(t_list **lst);
void	ready_to_greedy(t_list **lst_a, t_list **lst_b);

void	rec_info_1(t_list **lst_a, t_list **lst_b, t_info *info[]);
void	rec_info_2(t_info *info[], int info_size);
// void	ra_rb_case(t_info *info[], int idx);
// void	rra_rrb_case(t_info *info[], int idx);
void	rec_info_3(t_info *info[], int info_size);


void	sort_over_3nodes(t_list **lst_a, t_list **lst_b);








void	print(t_list *a, t_list *b);

#endif
