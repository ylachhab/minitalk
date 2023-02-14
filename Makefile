# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 19:42:54 by ylachhab          #+#    #+#              #
#    Updated: 2023/01/07 16:05:32 by ylachhab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S = server

NAME_C = client

NAME_SB = server_bonus

NAME_CB = client_bonus

FLAGS  = -Wall -Wextra -Werror

CC = cc

RM = rm -f

SRC_S  = server.c minitalk_utils.c

SRC_C  = client.c minitalk_utils.c

SRC_SB  = server_bonus.c minitalk_bonus_utils.c

SRC_CB  = client_bonus.c minitalk_bonus_utils.c

OBJS = $(SRC_S:.c=.o)

OBJC = $(SRC_C:.c=.o)

OBJSB = $(SRC_SB:.c=.o)

OBJCB = $(SRC_CB:.c=.o)

all: $(NAME_S) $(NAME_C)

printf/libftprintf.a :
	make -C printf all

%.o: %.c minitalk.h minitalk_bonus.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME_S) : printf/libftprintf.a $(OBJS)
	$(CC) $(FLAGS) $(OBJS) printf/libftprintf.a -o $(NAME_S)

$(NAME_C) : printf/libftprintf.a $(OBJC)
	$(CC) $(FLAGS) $(OBJC) printf/libftprintf.a -o $(NAME_C)


bonus : all $(OBJSB) $(OBJCB) printf/libftprintf.a
	$(CC) $(FLAGS) $(OBJSB) printf/libftprintf.a -o $(NAME_SB)
	$(CC) $(FLAGS) $(OBJCB) printf/libftprintf.a -o $(NAME_CB)

clean:
	$(RM) $(OBJS) $(OBJC) $(OBJSB) $(OBJCB)
	make -C printf clean

fclean: clean
	$(RM) $(NAME_S) $(NAME_C) $(NAME_SB) $(NAME_CB)
	make -C printf fclean

re: fclean all