#include <stdio.h>
#include "../libft.h"


int test_ft_strjoin()
{
	printf("------------\n----STRJOIN----\n------------\n");

	printf("res: %s\n",ft_strjoin("12345","blaope"));
	printf("res: %s\n",ft_strjoin("dzkaondpoazndoanfà!a à azazà","18198"));
	printf("res: %s\n",ft_strjoin("   ozj zaç ç çç ",NULL));
	printf("res: %s\n",ft_strjoin("",NULL));
	return (0);
}