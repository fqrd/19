#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

int test_ft_atoi()
{
	printf("------------\n----ATOI----\n------------\n");
	int i = 0;
	int lib;
	int own;
	char table[18][41] = {
		"0", 
		"-10", 
		"+30", 
		"--150", 
		"++190", 
		"-2147483647", 
		"+2147483647", 
		"-21474836470", 
		"21474836470", 
		" 19223372036854775807", 
		" 5e7", 
		" 7 9", 
		" - 5", 
		" + 6", 
		"-99999999999999999999999999", 
		"99999999999999999999999999", 
		"999999999999999999", 
		"-999999999999999999"
	};

	while (table[i] && i < 18)
	{
		lib = atoi(table[i]);
		own = ft_atoi(table[i]);
		(lib == own) ? printf("OK (%s) -> %d \n", table[i], own): printf("[ERROR] (%s) >> atoi(%d) != ft_atoi(%d)\n", table[i], lib, own);
		i++;
	}
	return (0);
}