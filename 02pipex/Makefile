# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 16:34:18 by donglee2          #+#    #+#              #
#    Updated: 2023/07/06 12:07:59 by donglee2         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -L./00libft -lft
MANDATORY_DIR = ./

MANDATORY_SRCS = pipex.c\
path.c\
exec_cmd.c\
init_variable.c\

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
RM = rm -rf

MAKE = make

LIBFT = libft.a

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C ./00libft bonus

$(NAME): $(MANDATORY_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(MANDATORY_OBJS) $(LDFLAGS)

clean:	
	$(RM) $(MANDATORY_OBJS)
	$(MAKE) -C ./00libft clean

fclean: clean
	$(RM) $(NAME) $(LIB)
	$(RM) 00libft/$(LIBFT)
re: fclean all
