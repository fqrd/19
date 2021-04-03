#include <stdio.h>
#include <ctype.h>

int	ft_tolower(int c);

int main()
{
	printf("---------------\n----TOLOWER----\n---------------\n");
	int i = 0;
	char string[57] = "§W[eST7´[EdCF0d:hc§ir} fà-5LDxié;1zL)y8'L0!:ùSm[Qe-";

	while (string[i] && i < 57)
	{
		int lib_tolower = tolower(string[i]);
		int test_tolower = ft_tolower(string[i]);
		if(lib_tolower == test_tolower)
			printf("OK (%c) -> %c \n", string[i], test_tolower);
		else
			printf("[ERROR] (%c) >> tolower(%d) != test_tolower(%d)\n", string[i], lib_tolower, test_tolower);
		i++;
	}
	return (0);
}