# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 16:34:18 by donglee2          #+#    #+#              #
#    Updated: 2023/06/19 16:47:54 by donglee2         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #


NAME = pipex
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

MANDATORY_DIR = ./mandatory_files

MANDATORY_SRCS = $(MANDATORY_DIR)/0_chk_arg_1.c\
$(MANDATORY_DIR)/0_chk_arg_2.c\
$(MANDATORY_DIR)/0_chk_arg_split.c\
$(MANDATORY_DIR)/1_instr_src_1.c\
$(MANDATORY_DIR)/1_instr_src_2.c\
$(MANDATORY_DIR)/2_instr_set_1.c\
$(MANDATORY_DIR)/2_instr_set_2.c\
$(MANDATORY_DIR)/2_instr_set_3.c\
$(MANDATORY_DIR)/3_sort_prep.c\
$(MANDATORY_DIR)/4_sort_rec_info_1_src_1.c\
$(MANDATORY_DIR)/4_sort_rec_info_1_src_2.c\
$(MANDATORY_DIR)/4_sort_rec_info_2_src.c\
$(MANDATORY_DIR)/4_sort_rec_info.c\
$(MANDATORY_DIR)/5_sort_instr_exec.c\
$(MANDATORY_DIR)/6_sort_1.c\
$(MANDATORY_DIR)/6_sort_2.c\
$(MANDATORY_DIR)/7_main.c\

BONUS_DIR = ./bonus_files

BONUS_SRCS = $(BONUS_DIR)/b_chk_arg_1_bonus.c\
$(BONUS_DIR)/b_chk_arg_2_bonus.c\
$(BONUS_DIR)/b_chk_arg_split_bonus.c\
$(BONUS_DIR)/b_get_next_line_bonus.c\
$(BONUS_DIR)/b_get_next_line_utils_bonus.c\
$(BONUS_DIR)/b_instr_exec_bonus.c\
$(BONUS_DIR)/b_instr_set_1_bonus.c\
$(BONUS_DIR)/b_instr_set_2_bonus.c\
$(BONUS_DIR)/b_instr_set_3_bonus.c\
$(BONUS_DIR)/b_instr_src_1_bonus.c\
$(BONUS_DIR)/b_instr_src_2_bonus.c\
$(BONUS_DIR)/b_main_bonus.c\


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

