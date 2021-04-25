/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:35:53 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/25 18:10:13 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ps;
	int 	i;
	char	*output;

	if (!s || !(*f))
		return (NULL);

	ps = (char *) s;
	i = 0;
	output = malloc (sizeof(char) * ft_strlen(ps) + 1);
	if (!output)
		return (NULL);
	while (ps[i])
	{
		output[i]= (*f)(i, ps[i]);
		i++;
	}
	return (output);
}

/*
char	yolo(unsigned int a, char c)
{
	if (a % 2 == 0 && c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int main(void)
{
	char *f = ft_strmapi("Well it's never bad to dream a little. It just hurt when you come back to reason.", &yolo);
	printf("%s\n", f);
}
*/