/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:34:49 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/24 15:53:17 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
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
			array[cell++] = ft_substr(str, start, (i - start));
			while (str[i] && str[i] == c)
				i++;
			start = i;
		}
		i++;
	}
	array[cell] = ft_substr(str, start, (i - start));
	return (array);
}

char	**ft_split(char const *s, char c)
{
	size_t	n;
	char	*ps;
	char	**array;

	ps = (char *) s;
	ps = ft_strtrim(ps, &c);
	n = count_splits(ps, c, 1);
	printf("trim: %s\n", ps);
	printf("n: %zu\n", n);
	array = malloc(sizeof(char *) * n + 1);
	array[n] = malloc(sizeof(char) * 1);
	if (!array || !array[n])
	{
		free(array[n]);
		free(array);
		return (NULL);
	}
	array[n] = '\0';
	split(array, ps, c);
	return (array);
}

/*
int main(void)
{
	char	**array = ft_split("aaaI caaan't find any GPU online,
	 everything is soldout. What a shaaame.a", 'a');
	printf("|%s|\n", array[0]);
	printf("|%s|\n", array[1]);
	printf("|%s|\n", array[2]);
	printf("|%s|\n", array[3]);
	printf("|%s|\n", array[4]);
	printf("|%s|\n", array[5]);
	printf("|%s|\n", array[6]);
	return (0);
}
*/
