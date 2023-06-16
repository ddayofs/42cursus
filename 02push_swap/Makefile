# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 20:01:47 by donglee2          #+#    #+#              #
#    Updated: 2023/06/16 20:02:53 by donglee2         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
MANDATORY_SRCS = 0_chk_arg_1.c\
0_chk_arg_2.c\
0_chk_arg_split.c\
1_instr_src_1.c\
1_instr_src_2.c\
2_instr_set_1.c\
2_instr_set_2.c\
2_instr_set_3.c\
3_sort_prep.c\
4_sort_rec_info_1_src_1.c\
4_sort_rec_info_1_src_2.c\
4_sort_rec_info_2_src.c\
4_sort_rec_info.c\
5_sort_instr_exec.c\
6_sort_1.c\
6_sort_2.c\
7_main.c\

BONUS_SRCS = b_chk_arg_1_bonus.c\
b_chk_arg_2_bonus.c\
b_chk_arg_split_bonus.c\
b_get_next_line_bonus.c\
b_get_next_line_utils_bonus.c\
b_instr_exec_bonus.c\
b_instr_set_1_bonus.c\
b_instr_set_2_bonus.c\
b_instr_set_3_bonus.c\
b_instr_src_1_bonus.c\
b_instr_src_2_bonus.c\
b_main_bonus.c\

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
RM = rm -rf

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(MANDATORY_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(MANDATORY_OBJS)

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS)
	touch $@

clean:	
	$(RM) $(MANDATORY_OBJS) $(BONUS_OBJS) bonus
 
fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
 
re: fclean all

