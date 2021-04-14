#include <stdio.h>
#include <ctype.h>
#include "../libft.h"
#include "../libft.h"

int test_ft_toupper()
{
	printf("---------------\n----TOUPPER----\n---------------\n");
	int error = 0;
	int i = 0;
	char string[57] = "§W[eST7´[EdCF0d:hc§ir} fà-5LDxié;1zL)y8'L0!ùSm[Qe-";

	while (string[i] && i < 57)
	{
		int lib_toupper = toupper(string[i]);
		int test_toupper = ft_toupper(string[i]);
		if(lib_toupper != test_toupper)
		{
			printf("[ERROR] (%c) >> toupper(%d) != test_toupper(%d)\n", string[i], lib_toupper, test_toupper);
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

