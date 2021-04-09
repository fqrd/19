#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "../libft.h"

int test_ft_memset()
{
	printf("------------\n----MEMSET----\n------------\n");

	char *s1 = "This is a test.";
	char *s2 = "This is a test.";

	printf("----\nown: %p\nlib: %p\n", s1, s2);
	ft_memset((void *)&s1, 't', 1);
	memset((void *)&s2, 't', 1);
	printf("own: %p\nlib: %p\n----\n", s1, s2);

	char *s3 = "This is a test.";
	char *s4 = "This is a test.";

	printf("----\nown: %p\nlib: %p\n", s3, s4);
	ft_memset((void *)&s3, 't', 2);
	memset((void *)&s4, 't', 2);
	printf("own: %p\nlib: %p\n----\n", s3, s4);

	char *s5 = "This is a test.";
	char *s6 = "This is a test.";

		printf("----\nown: %p\nlib: %p\n", s5, s6);
	ft_memset((void *)&s5, 't', 4);
	memset((void *)&s6, 't', 4);
	printf("own: %p\nlib: %p\n----\n", s5, s6);

	char *s7 = "This is a test.";
	char *s8 = "This is a test.";

	printf("----\nown: %p\nlib: %p\n", s7, s8);
	ft_memset((void *)&s7, 't', 8);
	memset((void *)&s8, 't', 8);
	printf("own: %p\nlib: %p\n----\n", s7, s8);

	// char *s9 = "This is a test.";
	// char *s10 = "This is a test.";

	// printf("----\nown: %p\nlib: %p\n", s9, s10);
	// memset((void *)&s10, 't', 16);
	// ft_memset((void *)&s9, 't', 16);
	// printf("own: %p\nlib: %p\n----\n", s9, s10);

	// char *s11 = "This is a test.";
	// char *s12 = "This is a test.";

	// printf("----\nown: %p\nlib: %p\n", s11, s12);
	// ft_memset((void *)&s11, 't', 32);
	// memset((void *)&s12, 't', 32);
	// printf("own: %p\nlib: %p\n----\n", s11, s12);

	// char *s13 = "This is a test.";
	// char *s14 = "This is a test.";

	// printf("----\nown: %p\nlib: %p\n", s13, s14);
	// ft_memset((void *)&s13, 't', 64);
	// memset((void *)&s14, 't', 64);
	// printf("own: %p\nlib: %p\n----\n", s13, s14);

	return (0);
}