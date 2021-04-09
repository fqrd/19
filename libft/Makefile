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

# TESTS !!!
TESTFLAGS = -lbsd
TESTSRC = $(filter-out main.c, $(wildcard ./tests/*.c))
TESTOBJ = $(TESTSRC:.c=.o)
TEST 	= libtest.a

test: $(TEST)

testobj: $(TESTSRC)
	$(CC) $(CFLAGS) -c $< $(TESTFLAGS) -o $(TESTOBJ)

$(TEST): $(TESTOBJ)
	ar rs $(TEST) $(TESTOBJ)

tclean: fclean
	rm -f $(TEST) *.gch ./tests/*.o

make ru: tclean fclean all test
