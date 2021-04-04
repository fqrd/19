#include <stdio.h>
#include <ctype.h>

int ft_alnum(int c);

int main()
{
	printf("---------------\n----ISALNUM----\n---------------\n");
	int i = 0;
	int lib;
	int own;
	char string[57] = {"§W[eST7´[EdCF0d:hc§ir} fàWLDxié;kzL)yO'L0!:ùSm[Qe-"};

	while (string[i] && i < 57)
	{
		lib = isalnum(string[i]);
		own = ft_alnum(string[i]);
		if(lib == own)
			printf("OK (%c) -> %d \n", string[i], own);
		else
			printf("[ERROR] (%c) >> isalnum(%d) != own(%d)\n", string[i], lib, own);
		i++;
	}
	return (0);
}