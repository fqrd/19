#include <stdio.h>
#include <string.h>
#include "../libft.h"


int test_ft_strlcpy()
{
	printf("------------\n----STRLCPY----\n------------\n");

	char dest[28] = "159784";
	char src[28] = "88888";

	printf("%lu / %s\n",ft_strlcpy(dest, src, 15), dest);
	printf("%lu / %s\n",strlcpy(dest, src, 15), dest);
	return (0);
}
