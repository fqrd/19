#include <stdio.h>
#include <string.h>
#include "../libft.h"
#include <stddef.h>


int test_ft_memmove ()
{
	printf("------------\n----MEMMOVE----\n------------\n");

	char ldest[15];
	char lsrc[15] = "\0";
	char odest[15];
	char osrc[15] = "\0";

	printf("Before memmove ldest = |%s| lsrc = |%s|\n", ldest, lsrc);
	memmove(ldest, lsrc, 15);
	printf("After memmove ldest = |%s|, lsrc = |%s|\n", ldest, lsrc);
	printf("---\n");
	printf("Before ft_memmove odest = |%s|, osrc = |%s|\n", odest, osrc);
	ft_memmove(odest, osrc, 15);
	printf("After ft_memmove odest = |%s|, osrc = |%s|\n", odest, osrc);
	return (0);
}