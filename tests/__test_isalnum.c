#include <stdio.h>
#include <ctype.h>

int ft_alnum(int c);

int main()
{
	printf("---------------\n----ISALNUM----\n---------------\n");
	int i = 0;
	char string[57] = {"§W[eST7´[EdCF0d:hc§ir} fàWLDxié;kzL)yO'L0!:ùSm[Qe-"};

	while (string[i] && i < 57)
	{
		int lib_isalnum = isalnum(string[i]);
		int test_isalnum = ft_alnum(string[i]);
		if(lib_isalnum == test_isalnum)
			printf("OK (%c) -> %d \n", string[i], test_isalnum);
		else
			printf("[ERROR] (%c) >> isalnum(%d) != test_isalnum(%d)\n", string[i], lib_isalnum, test_isalnum);
		i++;
	}
	return (0);
}