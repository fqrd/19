
#include <string.h>
#include <stdio.h>
#include "../libft.h"

int test_ft_memccpy ()
{
	printf("------------\n----MEMCCPY----\n------------\n");

	int a = '1';
	char ldest[16];
	char odest[16];
	char lsrc[16] = "159slozmpmmquit";
	char osrc[16] = "159slozmpmmquit";

	printf("---\nlib: %p / |%s|\nsrc: %p / |%s|\n", ldest, ldest, lsrc, lsrc);
	memccpy((void*) ldest, (void*) lsrc, a, 1);
	printf("lib: %p / |%s|\nsrc: %p / |%s|\n----", ldest, ldest, lsrc, lsrc);
	printf("---\nown: %p / |%s|\nsrc: %p / |%s|\n", odest, odest, osrc, osrc);
	ft_memccpy((void*) odest, (void*) osrc, a, 1);
	printf("own: %p / |%s|\nsrc: %p / |%s|\n----", odest, odest, osrc, osrc);
	
	return (0);
}