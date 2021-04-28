
#include <stdio.h>
#include "../libft.h"

char	yolo(unsigned int a, char c)
{
	if (a % 2 == 0 && c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int test_strmapi(void)
{
	char *f = ft_strmapi("Well it's never bad to dream a little. It just hurt when you come back to reason.", &yolo);
	printf("%s\n", f);
	return (0);
}