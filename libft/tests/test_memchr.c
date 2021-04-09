#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "../libft.h"


int test_ft_memchr()
{
	printf("------------\n----MEMCHR----\n------------\n");

	char s[15] = "abdgetrupsmqdsc";
	printf("%p\n", ft_memchr(s, 'c', 15));
	printf("%p\n", memchr(s, 'c', 15));

	char t[5][15] = {
		"c5'(YWy1rew)U!/",
		"pTv[N>=Gc1D~lgG",
		"NzcPV[""W=kw2v|",
		"Zp#xIzQ&(;QyVcw",
		"gteu'U{:g<NWnb#" // nill
	};

	int i = -1;
	while (++i < 5)
	{
		printf("---\n%p\n", ft_memchr(t[i], 'c', 15));
		printf("%p\n", memchr(t[i], 'c', 15));
	}
	return (0);
}