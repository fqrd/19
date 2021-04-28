CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all : $(NAME)

obj: $(SRC)
	$(CC) $(CFLAGS) -c $< -o $(OBJ)

$(NAME): $(OBJ)
	ar rs $(NAME) $(OBJ)

clean:
	rm -f *.o

fclean: clean
	rm -f ./$(NAME)

re: fclean all
