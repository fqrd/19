
#include <string.h>
#include <stdio.h>
#include "../libft.h"

int test_ft_memccpy ()
{
	printf("------------\n----MEMCCPY----\n------------\n");
	int error = 0;
	int a = 'i';
	char ldest[16];
	char odest[16];
	char lsrc[16] = "159slozmpmmquit";
	char osrc[16] = "159slozmpmmquit";

	memccpy((void*) ldest, (void*) lsrc, a, 1);
	ft_memccpy((void*) odest, (void*) osrc, a, 1);

	if ((strcmp(ldest, odest) != 0) || (strcmp(odest, osrc) != 0))
	{
		printf("ERROR: (lib): |%s|	!=	|%s| :(yours) / |%s| (src)\n", ldest, odest, lsrc);
		error = 1;
	}
	if (strcmp(lsrc, osrc) != 0)
	{
		printf("ERROR SRC CHANGED: (lib): |%s|	!=	|%s| :(yours)\n", lsrc, osrc);
		error = 1;
	}
	if (!error)
	{
		printf("OK\n");
	}

	
	return (0);
}
