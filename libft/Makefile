CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
BONUSFILES = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
SRCALL = $(wildcard *.c)
SRCMANDATORY = $(filter-out $(BONUSFILES), $(wildcard *.c))
MANDATORY = $(SRCMANDATORY:.c=.o)
ALL = $(SRCALL:.c=.o)

all : $(NAME)

$(NAME): $(MANDATORY)
	ar rs $(NAME) $(MANDATORY)

bonus : $(ALL)
	ar rs $(NAME) $(ALL)

clean:
	rm -f *.o

fclean: clean
	rm -f ./$(NAME)

re: fclean all
