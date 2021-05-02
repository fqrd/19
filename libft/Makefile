CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCMANDATORY =			\
	atoi.c				\
	bzero.c				\
	calloc.c			\
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
	isalnum.c			\
	isalpha.c			\
	isascii.c			\
	isdigit.c			\
	isprint.c			\
	memccpy.c			\
	memchr.c			\
	memcmp.c			\
	memcpy.c			\
	memmove.c			\
	memset.c			\
	strchr.c			\
	strdup.c			\
	strlcat.c			\
	strlcpy.c			\
	strlen.c			\
	strncmp.c			\
	strnstr.c			\
	strrchr.c			\
	tolower.c			\
	toupper.c			\

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
