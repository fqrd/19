#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n);

int main ()
{
	printf("------------\n----MEMMOVE----\n------------\n");

	char dest[15];
	char src[15] = "Hello you";
	printf("Before memmove dest = %s, src = %s\n", dest, src);
	ft_memmove(dest, src, 15);
	printf("After memmove dest = %s, src = %s\n", dest, src);
	return (0);
}