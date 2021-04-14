#include <stdio.h>
#include <ctype.h>
#include "../libft.h"

int test_ft_tolower()
{
	printf("---------------\n----TOLOWER----\n---------------\n");
	int error = 0;
	int i = 0;
	char string[57] = "§W[eST7´[EdCF0d:hc§ir} fà-5LDxié;1zL)y8'L0!:ùSm[Qe-";

	while (string[i] && i < 57)
	{
		int lib_tolower = tolower(string[i]);
		int test_tolower = ft_tolower(string[i]);
		if(lib_tolower != test_tolower)
		{
			printf("[ERROR] (%c) >> tolower(%d) != test_tolower(%d)\n", string[i], lib_tolower, test_tolower);
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