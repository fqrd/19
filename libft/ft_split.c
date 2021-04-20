/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:34:49 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/20 19:18:43 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static size_t	count_splits(char *str, unsigned char cc)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (i < ft_strlen(str) && str[i] != '\0')
	{
		// printf("#2 str[i]:	%c / cc: %u\n", str[i], cc);
		while (str[i] == cc && str[i])
			i++;
		while (str[i] != cc && str[i])
			i++;
		while (str[i] == cc && str[i])
			i++;
		count++;			
	}
	// printf("#3 count:	%ld\n", count);

	return (count);
}

static char		**execute_split(char *str, unsigned char cc, char **split, size_t count)
{
	size_t	i;
	size_t	end;
	size_t	start;
	char	*string;

	i = 0;
	start = 0;
	end = 0;
	
	while (i < ft_strlen(str) && i < count )
	{
		while (str[end] == cc && str[end] && end < ft_strlen(str))
			end++;
		while (str[end] != cc && str[end]  && end < ft_strlen(str))
			end++;
		while (str[end] == cc && str[end] && end < ft_strlen(str))
			end++;
		string = malloc(sizeof(char *) * ((end + 1) - start));
		if(!string)
			return (NULL);
		string[(end + 1) - start] = '\0';
		string = ft_substr(str, start, end - start);
		split[i] = string;

		printf("split[%ld]:	%s\n", i,  string);
		// printf("split[i]:	%s\n", split[i]);
		// split save malloc
		printf("start: %ld / end: %ld / length: %ld\n", start, end, end - start);
		start = end;
		i++;
	}
	printf("split[0]:	%s\n", split[0]);
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t			count;
	char			*cs;
	unsigned char	cc;
	char			**split;

	cs = (char *) s;
	cc = (unsigned char) c;
	printf("#1 str: %s / cc: %c\n", cs, cc);
	count = count_splits(cs, cc);
	printf("#2 count: %ld\n", count);
	
	split = malloc(sizeof(char**) * count);
	if (!split)
		return (NULL);
	split [count] = malloc(sizeof (char) * 1);
	if (!split[count])
		return (NULL);
	split[count][0] = '\0';

	if (!s)
		return (split);

	split = execute_split(cs, cc, split, count);


	// split[0] = malloc(sizeof(char *) * 9 + 1);
	// if(!split[0])
	// 	return (NULL);
	// split[0] = "Fuck that";
	// printf("#4 count:	%zu / split[i]:	%s\n", count, split[0]);
	
	return (split);
}

/*
int main(void)
{
	char **split;
	split = ft_split("JJJANA45A9AmAo", 'A');

	size_t i = 0;
	while (split[i][0])
	{
		printf("split[%ld]:	%s\n", i, split[i]);
		i++;
	}
	free (split);
	return (0);
}*/