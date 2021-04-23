/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:34:25 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/23 14:06:16 by fcaquard         ###   ########.fr       */
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
	if (!s1 || !set)
		return (NULL);
	start = from_left(s, ref);
	end = from_right(s, ref, ft_strlen(s), ft_strlen(ref));
	// printf("start: %zu / end: %zu / len: %zu / s: |%s|\n", start, end, end - start, s);
	output = ft_substr(s, start, (end - start) + 1);
	output[(end - start) + 1] = '\0';
	return (output);
}

/*
int	main(void)
{
	printf("---------------\n----STRTRIM----\n---------------\n");
	printf("%s\n", ft_strtrim("ox9ox9ox9ox9ox9ox9ox9ox9testox9ox9ox9ox9ox9ox9ox9ox9ox9ox9ox9ox9ox9", "ox9"));
	printf("%s\n", ft_strtrim("azhoonsnapazodnonosnaoaoazndnnodanzudnnazudn", "azhoo"));
	printf("%s\n", ft_strtrim("-à&é!'ç&énk'&péoj'à&éh!dàhipnzdk,ôd)&j&édà", "à"));
	printf("%s\n", ft_strtrim(" 	              		ppe	 ", " 	"));
	printf("%s\n", ft_strtrim("\t\npmmmmzmmmz\n", "\t\n"));
	printf("%s\n", ft_strtrim("09486oazjpazijdazdazd094", "094"));
	printf("%s\n", ft_strtrim("popopopopopopo", "po"));
	printf("%s\n", ft_strtrim("pémmémémémémém&,en&é!y e&!éy!&éye )&!éye !)&éye&é!çy ç!é!çé!çé", "é"));

	printf("|%s|\n", ft_strtrim("   xxxtripouille", "   x"));
	printf("|%s|\n", ft_strtrim("tripouille   xxx", "   x"));
	printf("|%s|\n", ft_strtrim("   xxxtripouille   x", "   x"));
	printf("|%s|\n", ft_strtrim("   xxx   xxx", "   x"));
	printf("|%s|\n", ft_strtrim("123", ""));
	printf("%p\n", ft_strtrim("", ""));
	return (0);
}
*/