CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC = $(filter-out main.c, $(wildcard *.c))
OBJ = $(SRC:.c=.o)

#! REMOVE
WLSLBSD = -lbsd


all : $(NAME)

obj: $(SRC)
	$(CC) $(CFLAGS) $(WLSLBSD) -c $< -o $(OBJ)

$(NAME): $(OBJ)
	ar rs $(NAME) $(OBJ)

clean:
	rm -f *.o

fclean: clean
	rm -f ./$(NAME)

re: fclean all
