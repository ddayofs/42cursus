# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 20:01:47 by donglee2          #+#    #+#              #
#    Updated: 2023/06/16 13:54:06 by donglee2         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
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

BONUS_SRCS = 

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
RM = rm -rf

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(MANDATORY_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(MANDATORY_OBJS)

bonus: $(BONUS_OBJS) $(MANDATORY_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(MANDATORY_OBJS) $(BONUS_OBJS)
	touch $@

clean:	
	$(RM) $(MANDATORY_OBJS) $(BONUS_OBJS) bonus
 
fclean: clean
	$(RM) $(NAME)
 
re: fclean all

