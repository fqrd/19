#include <stdio.h>
#include <string.h>
#include "../libft.h"

int test_ft_strncmp()
{
	printf("---------------\n----STRNCMP----\n---------------\n");
	int error = 0;
	int i = 0;
	// char master[57] = "§W[eST7´[EdCF0d:hc§ir} fà-5LDxié;1zL)y8'[Qe-\0";
	// char string[4][100] = {"", "§W[eST7´[EdCF0d:hc§ir} fà-5LDxié;1zL)y8'[Qe-\0", "fà-5LDxié;1zL)ùSm[Qe-\0", "§W[eS´[EdCF0d:hc§ir} fà-5LDxié;1zL)ùSm[Qe-8za,às@µsù\0"};
	char master[] = "At vero eos et accusamus et iusto odio dignissimo\0";
	char string[4][100] = {"At vero eos et accusamus et iusto odio \0", "At vero eos et accusamus et iusto odio dignissimos\0","At çero eos et accusamus et iusto’\0", "At vero eos et accusamus et iusto’\0"};

	while (string[i] && i < 4)
	{
		int lib = strncmp(master, string[i], 49);
		int own = ft_strncmp(master, string[i], 49);
		if(lib != own)
		{
			printf("ERROR (%d != %d)\n",lib,own);
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
