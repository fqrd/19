#include <stdio.h>
#include "../libft.h"


int test_ft_substr()
{
	printf("------------\n----SUBSTR----\n------------\n");

	char s[10] = "0123456789";
	printf("%s\n",ft_substr(s, 0, 1));
	printf("%s\n",ft_substr(s, 0, 2));
	printf("%s\n",ft_substr(s, 0, 3));
	printf("%s\n",ft_substr(s, 1, 1));
	printf("%s\n",ft_substr(s, 1, 2));
	printf("%s\n",ft_substr(s, 1, 3));
	printf("%s\n",ft_substr(s, 5, 3));
	// printf("%s\n",ft_substr(s, 5, 8));
	// printf("%s\n",ft_substr(s, 0, 0));
	// printf("%s\n",ft_substr(s, NULL, NULL));

	return (0);
}