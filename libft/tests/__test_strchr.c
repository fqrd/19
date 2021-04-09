#include <stdio.h>
#include <string.h>
#include "../libft.h"

int test_ft_strchr()
{
	printf("------------\n----STRCHR----\n------------\n");

	char str[5][100] = {"\0\0p\0r\0   	\n\ts","abcdefghijklmnopqrtuvw\0x\0y\ns", "", "abc789456123fopszerrrrrr", "s\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};
	char search = 's';
	char *lib;
	char *own;
	int i = 0;
	while (i < 5)
	{
		lib = strchr(str[i],search);
		own = ft_strchr(str[i],search);
		(lib == own) ? printf("OK (%s == %s) \n", lib, own): printf("[ERROR] (%s != %s)\n", lib, own);
		i++;
	}
	return (0);
}