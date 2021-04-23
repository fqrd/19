/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:34:25 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/23 19:18:52 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "libft.h"

static size_t	find_index(char *ps, char *pset)
{
	size_t	index;
	size_t	len;

	len = ft_strlen(pset);
	index = 0;
	while (*ps == *pset && *ps)
	{
		if (*(pset + 1) == '\0')
		{
			pset -= (len - 1);
			index += len;
		}
		else
			pset++;
		ps++;
	}
	// printf("s1: %s / set: %s\n", ps, pset);
	return (index);
}

static char	*reverse(char const *set)
{
	char	*pset;
	char	*rev;

	pset = (char *) set;
	rev = malloc(sizeof(char) * ft_strlen(set) + 1);
	if (!rev)
		return (NULL);
	pset += (ft_strlen(pset) - 1);
	while (pset - set >= 0)
		*rev++ = *pset--;
	*rev = '\0';
	// printf("set: %s\n", set);
	return (rev - ft_strlen(set));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ps;
	char	*pset;
	size_t	start;
	size_t	end;
	char	*output;

	pset = (char *) set;
	ps = (char *) s1;
	if (!s1 || !set)
		return (NULL);
	start = find_index(ps, pset);
	end = find_index(reverse(ps), reverse(pset));
	ps = (char *) s1;
	output = ft_substr(ps, start, ft_strlen(ps) - (start + end));
	return (output);
}

/*
int	main(void)
{
	printf("---------------\n----STRTRIM----\n---------------\n");
	printf("#1	|%s|\n", ft_strtrim("\t\t\t\t\tok\tok\t","\t"));
	printf("#2	|%s|\n", ft_strtrim("112234456ok654432211ok112234456","112234456"));
	printf("#3	|%s|\n", ft_strtrim("-$^µù=:;,&éé&'§ok-$^µù=:;,&éé&'§","-$^µù=:;,&éé&'§"));
	printf("#4	|%s|\n", ft_strtrim(" 	  ok 	  "," 	  "));
	printf("#5	|%s|\n", ft_strtrim("okokokokok","ok"));
	printf("#6	|%s|\n", ft_strtrim("okkokkkokk","okk"));
	printf("#6	|%s|\n", ft_strtrim("",""));
	return (0);
}*/