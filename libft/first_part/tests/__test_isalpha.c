#include <stdio.h>
#include <ctype.h>

int	ft_isalpha(int c);

int main()
{
	printf("---------------\n----ISALPHA----\n---------------\n");
	int i = 0;
	char string[57] = {"§W[eST7´[EdCF0d:hc§ir} fàWLDxié;kzL)yO'L0!:ùSm[Qe-"};

	while (string[i] && i < 57)
	{
		int lib_isalpha = isalpha(string[i]);
		int test_isalpha = ft_isalpha(string[i]);
		if(lib_isalpha == test_isalpha)
			printf("OK (%c) -> %d \n", string[i], test_isalpha);
		else
			printf("[ERROR] (%c) >> isalpha(%d) != test_isalpha(%d)\n", string[i], lib_isalpha, test_isalpha);
		i++;
	}
	return (0);
}