#include <stdio.h>
#include <stddef.h>
#include <strings.h>

void	ft_bzero(void *s, size_t n);

int main()
{

	char *s1 = "This is a test.";
	char *s2 = "This is a test.";

	printf("----\nown: %p\nlib: %p\n", s1, s2);
	ft_bzero((void *)&s1, 1);
	bzero((void *)&s2, 1);
	printf("own: %p\nlib: %p\n----\n", s1, s2);

	char *s3 = "This is a test.";
	char *s4 = "This is a test.";

	printf("----\nown: %p\nlib: %p\n", s3, s4);
	ft_bzero((void *)&s3, 2);
	bzero((void *)&s4, 2);
	printf("own: %p\nlib: %p\n----\n", s3, s4);

	char *s5 = "This is a test.";
	char *s6 = "This is a test.";

		printf("----\nown: %p\nlib: %p\n", s5, s6);
	ft_bzero((void *)&s5, 4);
	bzero((void *)&s6, 4);
	printf("own: %p\nlib: %p\n----\n", s5, s6);

	char *s7 = "This is a test.";
	char *s8 = "This is a test.";

	printf("----\nown: %p\nlib: %p\n", s7, s8);
	ft_bzero((void *)&s7, 8);
	bzero((void *)&s8, 8);
	printf("own: %p\nlib: %p\n----\n", s7, s8);

	// char *s9 = "This is a test.";
	// char *s10 = "This is a test.";

	// printf("----\nown: %p\nlib: %p\n", s9, s10);
	// bzero((void *)&s10, 16);
	// ft_bzero((void *)&s9, 16);
	// printf("own: %p\nlib: %p\n----\n", s9, s10);

	// char *s11 = "This is a test.";
	// char *s12 = "This is a test.";

	// printf("----\nown: %p\nlib: %p\n", s11, s12);
	// ft_bzero((void *)&s11, 32);
	// bzero((void *)&s12, 32);
	// printf("own: %p\nlib: %p\n----\n", s11, s12);

	// char *s13 = "This is a test.";
	// char *s14 = "This is a test.";

	// printf("----\nown: %p\nlib: %p\n", s13, s14);
	// ft_bzero((void *)&s13, 64);
	// bzero((void *)&s14, 64);
	// printf("own: %p\nlib: %p\n----\n", s13, s14);

	return (0);
}