# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/18 16:59:51 by fcaquard          #+#    #+#              #
#    Updated: 2021/07/18 17:28:58 by fcaquard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCMANDATORY =			\
	main.c

MANDATORY = $(SRCMANDATORY:.c=.o)
# BONUS = $(SRCBONUS:.c=.o)

all : $(NAME)

$(NAME): $(MANDATORY)
	ar rs $(NAME) $(MANDATORY)

# bonus : $(MANDATORY) $(BONUS)
# 	ar rs $(NAME) $(MANDATORY) $(BONUS)

clean:
	rm -f *.o

fclean: clean
	rm -f ./$(NAME)

re: fclean all

test: fclean all
	$(CC) $(CFLAGS) $(NAME) && ./a.out