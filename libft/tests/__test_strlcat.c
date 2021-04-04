/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __test_strlcat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:06:30 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/04 12:16:09 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <bsd/string.h>

unsigned long	ft_strlcat(char *dest, const char *src, unsigned long size);
int	ft_strncmp(char *s1, char *s2, unsigned long long n);

int main()
{
	printf("---------------\n----STRLCAT----\n---------------\n");

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
					150,
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
		if(ft_strncmp(tdest[i],txdest[i],sizes[i]) == 0)
		{
			// printf("OK!");
			printf("OK!\n%s\n%s\n", tdest[i] , txdest[i]);
		}
		else
		{
			printf("DIFFERENTS STRINGS:  %s != %s\n", tdest[i] , txdest[i]);
		}

		if(n_strlcat == x_strlcat)
		{
			// printf("OK!\n");
			printf("OK! (%d && %d)\n----\n", n_strlcat, x_strlcat);
		}
		else
			printf("DIFFERENTS OUTPUTS: %d != %d\n----\n", n_strlcat, x_strlcat);
		i++;
	}
	return (0);
}