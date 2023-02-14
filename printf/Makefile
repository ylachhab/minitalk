# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 23:28:00 by ylachhab          #+#    #+#              #
#    Updated: 2022/11/16 23:42:16 by ylachhab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

CC = cc

AR = ar rc

RM = rm -f

SRCS = 	ft_printf.c \
		ft_putchar.c \
		ft_putunsigned.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_printhexa.c \
		ft_hexaup.c \
		ft_putptr.c \
		ft_read.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@
	
$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)
	
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
