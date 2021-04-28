#include <stdlib.h>
#include "../libft.h"

int ft_split(void)
{
	char	**array = ft_split("aaaI caaan't find any GPU online, everything is soldout. What a shaaame.a", 'a');
	char	**array = ft_split("     ", ' ');
	char	**array = ft_split("", ' ');
	char	**array = ft_split("", 0);
	printf("|%s|\n", array[0]);
	printf("|%s|\n", array[1]);
	printf("|%s|\n", array[2]);
	printf("|%s|\n", array[3]);
	printf("|%s|\n", array[4]);
	printf("|%s|\n", array[5]);
	printf("|%s|\n", array[6]);
	free(array);
	return (0);
}