/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:34:49 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/20 18:07:42 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

static size_t	count_splits(char *str, unsigned char cc)
{
	size_t	count;
	size_t	i;

	count = 0;
	while (i < ft_strlen(str) && str[i] != '\0')
	{
		while (str[i] != cc)
			i++;
		if (str[i++] == cc)
		{
			count++;		
			while (str[i] == cc)
				i++;		
		}
	}
	return (count);
}

static char		**execute_split(char *str, unsigned char cc, char **split)
{
	size_t	i;
	size_t	end;
	ssize_t start;

	i = 0;
	start = 0;
	end = 0;
	while (i < ft_strlen(str) && split[i] != '\0')
	{
		while (str[end] != cc && str[end])
			end++;
		while (str[end] == cc && str[end])
			end++;
		if (start != end)
		{
			ft_substr(str, start, end - start);
			// spli save malloc
			start = end;
			i++;
		}
		else
			end++;
	}
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
	count = count_splits(s, cc);
	split = malloc(sizeof(char**) * count + 1);
	if (!split)
		return (NULL);
	split[count + 1] = '\0';
	if (!s)
		return (split);
	split = execute_split(cs, cc, &split);
	return (split);
}