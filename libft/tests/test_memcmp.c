#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "../libft.h"

int test_ft_memcmp()
{
	printf("------------\n----MEMCMP----\n------------\n");
	int error = 0;
	long unsigned int i = 0;
	while (i < 100)
	{
		char *s2[i];
		char *s1[i];
		if(sizeof(char *) <= i)
		{
			int r = ft_memcmp(s1,s2, i);
			int d = memcmp(s1,s2,i);
			if(r != d)
			{
				printf("ERROR\t[%d != %d]\t(%p | %p)\t[n: %ld]\n", d,r, s1,s2,i);
				error = 1;
			}
		}
		i++;
	}
	if (!error)
	{
		printf("OK\n");
	}
	return (0);
}
