#include <stdio.h>
#include <ctype.h>
#include "../libft.h"

int test_ft_isalpha()
{
	printf("---------------\n----ISALPHA----\n---------------\n");
	int error = 0;
	int i = 0;
	char string[57] = {"§W[eST7´[EdCF0d:hc§ir} fàWLDxié;kzL)yO'L0!:ùSm[Qe-"};

	while (string[i] && i < 57)
	{
		int lib_isalpha = isalpha(string[i]);
		int test_isalpha = ft_isalpha(string[i]);
		if(lib_isalpha != test_isalpha)
		{
			printf("[ERROR] (%c) >> isalpha(%d) != test_isalpha(%d)\n", string[i], lib_isalpha, test_isalpha);
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