/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:34:25 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/23 15:35:48 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "libft.h"

static size_t find_index(char *ps, char *pset)
{
	size_t 	index;
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
	char *pset;
	char *rev;
	
	pset = (char *) set;
	rev = malloc(sizeof(char) * ft_strlen(pset) + 1);
	if (!rev)
		return (NULL);
	pset += (ft_strlen(pset) - 1);
	while (pset - set >= 0)
		*rev++ = *pset--;
	*rev = '\0';
	// printf("#3 rev: %s / pset: %s\n", rev, pset + 1);
	return (rev - ft_strlen(set));
}


char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*ps;
	char	*pset;
	char	*output;

	pset = (char *)	set;
	ps = (char *) s1;
	start = find_index(ps, pset);
	ps = reverse(s1);
	pset = reverse(set);
	end = find_index(ps, pset);
	output = ft_substr(s1, start, ft_strlen(s1) - (start + end));
	printf("pset: %s / ps: %s / start: %zu / end: %zu\n", pset, ps, start, end);
	return (output);
}




// int main(void)
// {
// 	printf("result:	%s\n",ft_strtrim("abcopqrstabc55absabc", "abc"));
// 	return (0);
// }
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