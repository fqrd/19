#include <stdio.h>
#include <ctype.h>

int	ft_isdigit(int c);

int main()
{
	printf("---------------\n----ISDIGIT----\n---------------\n");
	int i = 0;
	char string[57] = {"§W[eST7´[EdCF0d:hc§ir} fà-5LDxié;1zL)y8'L0!:ùSm[Qe-"};

	while (string[i] && i < 57)
	{
		int lib_isdigit = isdigit(string[i]);
		int test_isdigit = ft_isdigit(string[i]);
		if(lib_isdigit == test_isdigit)
			printf("OK (%c) -> %d \n", string[i], test_isdigit);
		else
			printf("[ERROR] (%c) >> isdigit(%d) != test_isdigit(%d)\n", string[i], lib_isdigit, test_isdigit);
		i++;
	}
	return (0);
}