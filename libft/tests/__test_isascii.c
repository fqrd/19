#include <stdio.h>
#include <ctype.h>
#include "../libft.h"

int test_ft_isascii()
{
	printf("---------------\n----ISASCII----\n---------------\n");
	int i = 0;
	char string[57] = {"§W[eST7´[EdCF0d:hc§ir} fàWLDxié;kzL)yO'L0!:ùSm[Qe-"};

	while (string[i] && i < 57)
	{
		int lib_isascii = isascii(string[i]);
		int test_isascii = ft_isascii(string[i]);
		if(lib_isascii == test_isascii)
			printf("OK (%c) -> %d \n", string[i], test_isascii);
		else
			printf("[ERROR] (%c) >> isascii(%d) != test_isascii(%d)\n", string[i], lib_isascii, test_isascii);
		i++;
	}
	return (0);
}