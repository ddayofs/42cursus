# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 20:01:47 by donglee2          #+#    #+#              #
#    Updated: 2023/06/14 15:00:25 by donglee2         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
MANDATORY_SRCS = chk_arg_1.c\
chk_arg_2.c\
chk_arg_split.c\
instr_set_1.c\
instr_set_2.c\
instr_set_3.c\
instr_src_1.c\
instr_src_2.c\
main.c\
sort_instr_exec.c\
sort_prep.c\
sort_rec_info_1.c\
sort_rec_info_2.c\
sort_rec_info_3.c\
sort_rec_info_src.c\
sort.c\

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

