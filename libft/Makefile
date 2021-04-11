CC = gcc
CFLAGS = -Wall -Wextra -Werror
EXEC = libft.a
SRC = $(filter-out main.c, $(wildcard *.c))
OBJ = $(SRC:.c=.o)

#! REMOVE
WLSLBSD = -lbsd


all : $(EXEC)

obj: $(SRC)
	$(CC) $(CFLAGS) $(WLSLBSD) -c $< -o $(OBJ)

$(EXEC): $(OBJ)
	ar rs $(EXEC) $(OBJ)

clean:
	rm -f *.o

fclean: clean
	rm -f ./$(EXEC)

re: fclean all

# TESTS !!!
TESTFLAGS = -lbsd
TESTSRC = $(filter-out main.c, $(wildcard ./tests/*.c))
TESTOBJ = $(TESTSRC:.c=.o)
TEST 	= libtest.a

test: $(TEST)

testobj: $(TESTSRC)
	$(CC) $(CFLAGS) $(WLSLBSD) -c $< -o $(TESTOBJ)

$(TEST): $(TESTOBJ)
	ar rs $(TEST) $(TESTOBJ)

tclean: fclean
	rm -f ./$(TEST) ./*.gch ./tests/*.o ./*.out

oclean: clean
	rm -f */*.o

ru: tclean fclean all test

run: test all
	$(CC) main.c $(TEST) $(EXEC) && ./a.out
