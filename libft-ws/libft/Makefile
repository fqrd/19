# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/05 13:19:35 by fcaquard          #+#    #+#              #
#    Updated: 2021/05/05 13:19:56 by fcaquard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCMANDATORY =			\
	ft_atoi.c			\
	ft_bzero.c			\
	ft_calloc.c			\
	ft_itoa.c			\
	ft_putchar_fd.c		\
	ft_putendl_fd.c		\
	ft_putnbr_fd.c		\
	ft_putstr_fd.c		\
	ft_split.c			\
	ft_strjoin.c		\
	ft_strmapi.c		\
	ft_strtrim.c		\
	ft_substr.c			\
	ft_isalnum.c		\
	ft_isalpha.c		\
	ft_isascii.c		\
	ft_isdigit.c		\
	ft_isprint.c		\
	ft_memccpy.c		\
	ft_memchr.c			\
	ft_memcmp.c			\
	ft_memcpy.c			\
	ft_memmove.c		\
	ft_memset.c			\
	ft_strchr.c			\
	ft_strdup.c			\
	ft_strlcat.c		\
	ft_strlcpy.c		\
	ft_strlen.c			\
	ft_strncmp.c		\
	ft_strnstr.c		\
	ft_strrchr.c		\
	ft_tolower.c		\
	ft_toupper.c		\

SRCBONUS =				\
	ft_lstadd_back.c	\
	ft_lstadd_front.c	\
	ft_lstclear.c		\
	ft_lstdelone.c		\
	ft_lstiter.c		\
	ft_lstlast.c		\
	ft_lstmap.c			\
	ft_lstnew.c			\
	ft_lstsize.c		\

MANDATORY = $(SRCMANDATORY:.c=.o)
BONUS = $(SRCBONUS:.c=.o)

all : $(NAME)

$(NAME): $(MANDATORY)
	ar rs $(NAME) $(MANDATORY)

bonus : $(MANDATORY) $(BONUS)
	ar rs $(NAME) $(MANDATORY) $(BONUS)

clean:
	rm -f *.o

fclean: clean
	rm -f ./$(NAME)

re: fclean all
