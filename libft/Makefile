CC = gcc
CFLAGS = -Wall -Wextra -Werror
EXEC = libft.a
SRC = $(filter-out main.c, $(wildcard *.c))
OBJ = $(SRC:.c=.o)

all : $(EXEC)

obj: $(SRC)
	$(CC) $(CFLAGS) -c $< -o $(OBJ)

$(EXEC): $(OBJ)
	ar rs $(EXEC) $(OBJ)

clean:
	rm -f *.o

fclean: clean
	rm -f $(EXEC)

re: fclean all