#include <stdio.h>
#include <string.h>
#include "../libft.h"


int test_ft_strlcat()
{
	printf("---------------\n----STRLCAT----\n---------------\n");
	int error = 0;

	char tdest[6][120] = 	{
		"Asturia",
							"Pénéloppe Cruz",
							"what a beautiful sunrise",
							"Leave it to me!",
							"Lorem ipsum sit amet",
							""
							};

	char txdest[6][120] = 	{
		"Asturia",
						"Pénéloppe Cruz",
						"what a beautiful sunrise",
						"Leave it to me!",
						"Lorem ipsum sit amet",
						""
						};

	char srcs[6][150] = 	{
		"1234567",
						" is quite a beauty",
						" for my last day alive",
						" I don't know what I'm doing",
						" Dorean hecta sàç!è§('\"\'(§èinorsys pace",
						"P"
						};
	
	int sizes[6]= 	{ 150,
					-1,
					150,
					150,
					150,
					150	
					};

	int i = 0;
	while(i < 6)
	{
		int n_strlcat = strlcat(tdest[i],srcs[i] ,sizes[i]);
		int x_strlcat = ft_strlcat(txdest[i], srcs[i],sizes[i]);
		if(strncmp(tdest[i],txdest[i],sizes[i]) != 0)
		{
			printf("DIFFERENTS STRINGS:  %s != %s\n", tdest[i] , txdest[i]);
			error = 1;
		}
		if(n_strlcat != x_strlcat)
		{
			printf("DIFFERENTS OUTPUTS: %d != %d\n----\n", n_strlcat, x_strlcat);	
			error = 1;
		}
		i++;
	}
	if(!error)
	{
		printf("OK\n");
	}
	return (0);
}
