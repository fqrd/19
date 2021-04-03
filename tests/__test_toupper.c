#include <stdio.h>
#include <ctype.h>

int	ft_toupper(int c);

int main()
{
	printf("---------------\n----TOUPPER----\n---------------\n");
	int i = 0;
	char string[57] = "§W[eST7´[EdCF0d:hc§ir} fà-5LDxié;1zL)y8'L0!ùSm[Qe-";

	while (string[i] && i < 57)
	{
		int lib_toupper = toupper(string[i]);
		int test_toupper = ft_toupper(string[i]);
		if(lib_toupper == test_toupper)
			printf("OK (%c) -> %c \n", string[i], test_toupper);
		else
			printf("[ERROR] (%c) >> toupper(%d) != test_toupper(%d)\n", string[i], lib_toupper, test_toupper);
		i++;
	}
	return (0);
}

