#include "libtest.h"
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	printf("%d\n", test_ft_atoi());
	printf("%d\n", test_ft_isalpha());
	printf("%d\n", test_ft_isalnum());
	printf("%d\n", test_ft_isascii());
	printf("%d\n", test_ft_isdigit());
	printf("%d\n", test_ft_isprint());
	printf("%p\n", test_ft_memccpy());
	printf("%p\n", test_ft_memchr());
	printf("%d\n", test_ft_memcmp());
	printf("%p\n", test_ft_memcpy());
	printf("%p\n", test_ft_memmove());
	printf("%p\n", test_ft_memset());
	printf("%ls\n", test_ft_strchr());
	// printf("%d\n", test_ft_strlcat());
	// printf("%d\n", test_ft_strlcpy());
	printf("%d\n", test_ft_strlen());
	printf("%d\n", test_ft_strncmp());
	// printf("%ls\n", test_ft_strnstr());
	printf("%ls\n", test_ft_strrchr());
	printf("%d\n", test_ft_tolower());
	printf("%d\n", test_ft_toupper());
	test_ft_bzero();
	// printf("%d\n", test_ft_());
	return (0);
}
