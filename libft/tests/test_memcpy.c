
#include <string.h>
#include <stdio.h>
#include "../libft.h"

int test_ft_memcpy ()
{
	printf("------------\n----MEMCPY----\n------------\n");

	char ldest[16];
	char odest[16];
	char src[16] = "abcdefghijklmnop";
	
	printf("---\nbefore:\nlib: %p / %s\nown: %p / %s\nsrc: %p / %s\n", ldest, ldest, odest, odest, src, src);
	memcpy(ldest, src, 10);
	ft_memcpy(odest, src, 10);
	printf("---\nafter:\nlib: %p / %s\nown: %p / %s\nsrc: %p / %s\n----", ldest, ldest, odest, odest, src, src);
	
	return (0);
}