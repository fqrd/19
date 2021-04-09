#include <stdio.h>
#include <bsd/string.h>
#include "../libft.h"

size_t	strlcpy(char *dst, const char *src, size_t size);

int test_ft_strlcpy()
{
	printf("------------\n----STRLCPY----\n------------\n");

	char dest[28] = "159784";
	char src[28] = "88888";

	printf("%ld / %s\n",ft_strlcpy(dest, src, 15), dest);
	printf("%ld / %s\n",strlcpy(dest, src, 15), dest);
	return (0);
}