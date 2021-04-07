#include <stdio.h>
#include <bsd/string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size);

int main()
{
	char dest[28] = "159784";
	char src[28] = "88888";

	printf("%ld / %s\n",ft_strlcpy(dest, src, 15), dest);
	printf("%ld / %s\n",strlcpy(dest, src, 15), dest);
	return (0);
}