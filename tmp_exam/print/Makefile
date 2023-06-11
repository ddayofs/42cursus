# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 14:43:03 by donglee2          #+#    #+#              #
#    Updated: 2023/05/30 16:50:25 by donglee2         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
MANDATORY_SRCS = ft_printf.c\
ft_putchar.c\
ft_putstr.c\
ft_putnbr_base_ll.c\

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
ARRC = ar -cr
RM = rm -rf

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(MANDATORY_OBJS)
	$(ARRC) $(NAME) $(MANDATORY_OBJS)

clean:
	$(RM) $(MANDATORY_OBJS)
 
fclean: clean
	$(RM) $(NAME)
 
re: fclean all