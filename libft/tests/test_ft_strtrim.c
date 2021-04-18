#include <stdio.h>
#include "../libft.h"

int	test_ft_strtrim(void)
{
	printf("---------------\n----STRTRIM----\n---------------\n");

	printf("%s\n", ft_strtrim("ox9ox9ox9ox9ox9ox9ox9ox9testox9ox9ox9ox9ox9ox9ox9ox9ox9ox9ox9ox9ox9", "ox9"));
	return (0);
}