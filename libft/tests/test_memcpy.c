
#include <string.h>
#include <stdio.h>
#include "../libft.h"

int test_ft_memcpy(void)
{
	printf("------------\n----MEMCPY----\n------------\n");
	
	int error = 0;
	int i = 0;
	
	int size[4] = { 10,100,5,15};
	char ldest[100];
	char odest[100];
	char src[4][20] = {
		"d:hc§"
		,"5LDxié;1z"
		,";1zL)y8'L0ù!:Sm[Qe-"
		,"§1W[eST7´[EdCF"
	};

	while (i < 4)
	{
		memcpy(ldest, src[i], size[i]);
		ft_memcpy(odest, src[i], size[i]);
		if (strcmp(ldest, odest) != 0)
		{
			printf("ERROR: (lib): |%s|	!=	|%s| :(yours)\n", ldest, odest);
			error = 1;
		}
		i++;
	}
	
	if (!error)
	{
		printf("OK\n");
	}
	
	return (0);
}
