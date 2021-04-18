/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:34:25 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/18 16:45:31 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "libft.h"

static	size_t	from_left(char *s, char *ref)
{
	size_t	istr;
	size_t	iref;
	size_t	output;

	istr = 0;
	iref = 0;
	output = 0;
	if (s[istr] == ref[iref])
	{
		while (s[istr] == ref[iref] && s[istr] != '\0')
		{
			if (ref[iref + 1] == '\0')
			{
				iref = 0;
				output = istr + 1;
			}
			else
				iref++;
			istr++;
		}
	}
	return (output);
}

static	size_t	from_right(char *s, char *ref, size_t ls, size_t lref)
{
	size_t	istr;
	size_t	iref;
	size_t	output;

	istr = ls;
	iref = lref;
	output = ls;
	if (s[istr] == ref[iref])
	{
		while (s[istr] == ref[iref] && istr > 0)
		{
			if (iref == 0)
			{
				iref = lref - 1;
				output = istr;
			}
			else
				iref--;
			istr--;
		}
	}
	return (output);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	char	*ref;
	char	*output;
	size_t	start;
	size_t	end;

	ref = (char *) set;
	s = (char *) s1;
	output = (char *) s;
	start = from_left(s, ref);
	end = from_right(s, ref, ft_strlen(s), ft_strlen(ref));
	if (end <= start)
		return ("");
	output = malloc(sizeof(char *) * (end - start + 1));
	if (!output)
		return (NULL);
	output = ft_substr(s, start, end - start);
	output[end - start] = '\0';
	return (output);
}
