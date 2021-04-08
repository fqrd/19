#include <stdio.h>
#include <stddef.h>
#include <string.h>

int ft_memcmp(const void *s1, const void *s2, size_t n);

int main()
{
	printf("------------\n----MEMCMP----\n------------\n");

	long unsigned int i = 0;
	while (i < 100)
	{
		char *s2[i];
		char *s1[i];
		if(sizeof(char *) <= i)
		{
			int r = ft_memcmp(s1,s2, i);
			int d = memcmp(s1,s2,i);
			if(r == d)
			{
				printf("OK\t[%d == %d]\t(%p | %p)\t[n :%ld]\n", d,r, s1,s2,i);
			}
			else{
				printf("ERROR\t[%d != %d]\t(%p | %p)\t[n: %ld]\n", d,r, s1,s2,i);
			}
		}
		i++;
	}
}