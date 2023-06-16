/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:44:12 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/16 18:49:17 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}t_list;

//chk_arg_1_bonus.c
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
int		chk_arg(char *str, t_list **lst_a);

//chk_arg_2_bonus.c
void	print_err(void);
void	if_plus(char *str);
int		chk_sorted(t_list *lst);
int		chk_dup(t_list	*lst);

//chk_arg_split_bonus.c
char	**ft_split(char const *s, char c);

//instr_src_1_bonus.c
t_list	*ft_lstnew(int integer);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);

//instr_src_2_bonus.c
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

//b_instr_exec_bonus.c
void	chk_exec_instr(t_list **lst_a, t_list **lst_b, char	*str);

//b_instr_set_1_bonus.c
void	sa(t_list **lst);
void	sb(t_list **lst);
void	pa(t_list **lst_a, t_list **lst_b);
void	pb(t_list **lst_b, t_list **lst_a);

//b_instr_set_2_bonus.c
void	ra(t_list **lst);
void	rb(t_list **lst);
void	rr(t_list **lst_a, t_list **lst_b);

//b_instr_set_3_bonus.c
void	rra(t_list **lst);
void	rrb(t_list **lst);
void	rrr(t_list **lst_a, t_list **lst_b);

#endif