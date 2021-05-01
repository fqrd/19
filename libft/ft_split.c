/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:34:49 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/01 13:06:09 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static size_t	count_splits(char *str, unsigned char c, size_t n)
{
	while (*str)
	{
		if (*str && *str == c)
		{
			while (*str && *str == c)
				str++;
			n++;
		}
		str++;
	}
	return (n);
}

static char	**cmalloc(char *sub, char **arr, size_t cell)
{
	arr[cell] = sub;
	if (!arr[cell])
	{
		arr = arr - cell;
		while (*arr)
			free(*arr++);
		return (NULL);
	}
	return (arr);
}

static char	**split(char **array, char *str, unsigned char c)
{
	size_t	i;
	size_t	start;
	size_t	cell;

	cell = 0;
	start = 0;
	i = start;
	while (str[i])
	{
		if (str[i] && str[i] == c)
		{
			if (!cmalloc(ft_substr(str, start, (i - start)), array, cell))
				return (NULL);
			cell++;
			while (str[i] && str[i] == c)
				i++;
			start = i;
		}
		i++;
	}
	if (!cmalloc(ft_substr(str, start, (i - start)), array, cell))
		return (NULL);
	return (array);
}

#include <stdio.h>
char	**ft_split(char const *s, char c)
{
	size_t	n;
	char	*ps;
	char	**array;

	if (!s)
		return (NULL);
	n = 0;
	ps = ft_strtrim((char *) s, &c);
	if (!ps)
		return (NULL);
	if (ft_strlen(ps))		
		n = count_splits(ps, c, 1);
	array = malloc(sizeof(char *) * n + 1 );
	if (!array)
		return (NULL);
	array[n] = NULL;
	if(n)
	{	
		if (!split(array, ps, c))
			return (NULL);
	}
	free(ps);
	return (array);
}
