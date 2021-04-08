#include <stdio.h>
#include <stddef.h>
#include <string.h>

void *ft_memchr(const void *s, int c, size_t n);


int main()
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
}