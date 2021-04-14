#include <stdio.h>
#include <ctype.h>
#include "../libft.h"

int test_ft_isdigit()
{
	printf("---------------\n----ISDIGIT----\n---------------\n");
	int error = 0;
	int i = 0;
	char string[57] = {"§W[eST7´[EdCF0d:hc§ir} fà-5LDxié;1zL)y8'L0!:ùSm[Qe-"};

	while (string[i] && i < 57)
	{
		int lib_isdigit = isdigit(string[i]);
		int test_isdigit = ft_isdigit(string[i]);
		if(lib_isdigit != test_isdigit)
		{
			printf("[ERROR] (%c) >> isdigit(%d) != test_isdigit(%d)\n", string[i], lib_isdigit, test_isdigit);
			error = 1;
		}
		i++;
	}
	if(!error)
	{
		printf("OK");
	}
	return (0);
}