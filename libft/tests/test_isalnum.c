#include <stdio.h>
#include <ctype.h>
#include "../libft.h"

int test_ft_isalnum()
{
	printf("---------------\n----ISALNUM----\n---------------\n");
	int error =0;
	int i = 0;
	int lib;
	int own;
	char string[57] = {"§W[eST7´[EdCF0d:hc§ir} fàWLDxié;kzL)yO'L0!:ùSm[Qe-"};

	while (string[i] && i < 57)
	{
		lib = isalnum(string[i]);
		own = ft_isalnum(string[i]);
		if(lib != own)
		{
			printf("[ERROR] (%c) >> isalnum(%d) != own(%d)\n", string[i], lib, own);
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