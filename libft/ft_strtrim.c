/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:34:25 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/23 16:27:59 by fcaquard         ###   ########.fr       */
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
	return (index);
}

static char	*reverse(char const *set)
{
	char	*pset;
	char	*rev;

	pset = (char *) set;
	rev = malloc(sizeof(char) * ft_strlen(pset) + 1);
	if (!rev)
		return (NULL);
	pset += (ft_strlen(pset) - 1);
	while (pset - set >= 0)
		*rev++ = *pset--;
	*rev = '\0';
	return (rev - ft_strlen(set));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*ps;
	char	*pset;
	char	*output;

	if (!s1 || !set)
		return (NULL);
	pset = (char *) set;
	ps = (char *) s1;
	start = find_index(ps, pset);
	ps = reverse(s1);
	pset = reverse(set);
	end = find_index(ps, pset);
	output = malloc(sizeof(char) * (ft_strlen(s1) - (start + end)) + 1);
	if (!output)
		return (NULL);
	output = ft_substr((char *)s1, start, ft_strlen(s1) - (start + end));
	return (output);
}
