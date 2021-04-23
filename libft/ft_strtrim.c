/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:34:25 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/23 23:14:56 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "libft.h"

int	check_char(char c, char *test)
{
	while (*test)
	{
		if ((unsigned char) *test++ == (unsigned char) c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	len;
	char	*output;
	int 	error;

	error = 0;
	if(!s1 || !ft_strlen(s1))
		error = 1;
	i = 0;
	while (s1[i] && check_char((char) s1[i], (char *) set))
		i++;
	start = i;
	i = ft_strlen(s1);
	while (--i > 0 && check_char((char) s1[i], (char *) set));
	printf("start: %zu / i: %zu\n", start, i);
	if (i <= start)
	{
		len = 0;
		error = 1;
	}
	else
		len = (i - start) + 1;
	output = malloc(sizeof(char) * len + 1);
	if (!output)
		return (NULL);
	if (error)
		output[0] = '\0';
	else
		output = ft_substr(s1, start, len);
	return (output);
}

/*
int	main(void)
{
	printf("---------------\n----STRTRIM----\n---------------\n");
	printf("#1	|%s|\n", ft_strtrim("\t\t\t\t\tok\tok\t","\t")); 								// |ok	ok|
	printf("#2	|%s|\n", ft_strtrim("11223488456ok8654432211ok1122394456","1234756")); 			// |ok654432211ok|
	printf("#3	|%s|\n", ft_strtrim("-$^µù=:;,&éé&'§ok-$^µù=:;,&éé&'§","-$^µù=:;,&éé&'§")); 	// |ok|
	printf("#4	|%s|\n", ft_strtrim(" 	  ok 	  "," 	  "));  								// |ok|
	printf("#5	|%s|\n", ft_strtrim("okokokokok","ok")); 										// ||
	printf("#6	|%s|\n", ft_strtrim("okkokkkokk","okk")); 										// |k|
	printf("#7	|%s|\n", ft_strtrim("   xxx   xxx", " x")); 													// |(null)|
	printf("#8	|%s|\n", ft_strtrim("", "123")); 													// |(null)|
	printf("#9	|%s|\n", ft_strtrim("123", "")); 													// |(null)|
	printf("#10	|%s|\n", ft_strtrim("", "")); 													// |(null)|
	return (0);
}
*/
