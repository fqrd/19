/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:34:49 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/25 17:52:00 by fcaquard         ###   ########.fr       */
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

	ps = ft_strtrim((char *) s, &c);
	n = count_splits(ps, c, 1);
	if (!s || !ft_strlen(s))
		n = 0;
	array = malloc(sizeof(char *) * n + 1);
	if (!array)
	{
		free(array);
		return (NULL);
	}
	array[n] = NULL;
	split(array, ps, c);
	free(ps);
	return (array);
}
