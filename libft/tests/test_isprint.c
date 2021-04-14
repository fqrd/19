#include <stdio.h>
#include <ctype.h>
#include "../libft.h"

int test_ft_isprint()
{
	printf("---------------\n----ISPRINT----\n---------------\n");
	int error = 0;
	int i = 0;
	char string[57] = {"§W[eST7´[EdCF0d:hc§ir} fà-5LDxié;1zL)y8'L0!:ùSm[Qe-"};

	while (string[i] && i < 57)
	{
		int lib_isprint = isprint(string[i]);
		int test_isprint = ft_isprint(string[i]);
		if(lib_isprint != test_isprint)
		{
			printf("[ERROR] (%c) >> isprint(%d) != test_isprint(%d)\n", string[i], lib_isprint, test_isprint);
			error = 1;
		}
		i++;
	}
	if(!error)
	{
		printf("OK\n");
	}
	return (0);
}