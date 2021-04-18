
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include "../libft.h"

int test_ft_memccpy ()
{
	printf("------------\n----MEMCCPY----\n------------\n");
	int error = 0;
	char *lres;
	char *ores;
	char *a = 		"159slozmpmmquit";
	char ldest[16];
	char odest[16];
	char lsrc[16] = "159slozmpmmquit";
	char osrc[16] = "159slozmpmmquit";

	while(*a)
	{
		lres = memccpy((void*) ldest, (void*) lsrc, *a, 16);
		ores = ft_memccpy((void*) odest, (void*) osrc, *a, 16);
		// memccpy((void*) ldest, (void*) lsrc, *a, 16);
		// ft_memccpy((void*) odest, (void*) osrc, *a, 16);

		// if (strcmp(ldest, odest) != 0)
		if (strcmp(lres, ores) != 0)
		{
			printf("ERROR: (lib): |%s|	!=	|%s| :(yours) / |%s| (src)\n", lres, ores, lsrc);
			// printf("ERROR: (lib): |%s|	!=	|%s| :(yours) / |%s| (src)\n", ldest, odest, lsrc);
			error = 1;
		}
		else
		{
			printf("ok\n");
		}

		if (strcmp(lsrc, osrc) != 0)
		{
			printf("ERROR SRC CHANGED: (lib): |%s|	!=	|%s| :(yours)\n", lsrc, osrc);
			error = 1;
		}
		a++;
	}
	if (!error)
	{
		printf("OK\n");
	}

	return (0);
}
