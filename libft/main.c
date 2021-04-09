#include "libft.h"
#include <stdio.h>

 int main()
 {
	int i = 0;
	char string[57] = "§W[eST7´[EdCF0d:hc§ir} fàWLDxié;kzL)yO'L0!:ùSm[Qe-";

	while (string[i] && i < 57)
	{
		printf("%d\n",ft_isalpha(string[i]));
		i++;
	}
 }