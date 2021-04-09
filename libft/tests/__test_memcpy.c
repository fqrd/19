
#include <string.h>
#include <stdio.h>
#include "../libft.h"

int test_ft_memcpy ()
{
	printf("------------\n----MEMCPY----\n------------\n");

	char dest1[16];
	char dest2[16];
	char src[16] = "abcdefghijklmnop";
	printf("---\nbefore:\nlib: %p / %s\nown: %p / %s\nsrc: %p / %s\n", dest1, dest1, dest2, dest2, src, src);
	memcpy((void*) dest1, (void*) src, 15);
	ft_memcpy((void*) dest2, (void*) src, 15);
	printf("---\nafter:\nlib: %p / %s\nown: %p / %s\nsrc: %p / %s\n----", dest1, dest1, dest2, dest2, src, src);
	
	return (0);
}