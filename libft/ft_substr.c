/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:30:37 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/22 13:26:52 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ps;
	char			*substring;
	size_t			i;
	size_t			llock;

	llock = 0;
	i = 0;
	while (start + llock < ft_strlen(s) && llock < len)
		llock++;
	substring = malloc(sizeof(unsigned char *) * (llock));
	if (!substring || s == NULL || len == 0)
		return (NULL);
	// substring[llock] = '\0';
	if (start > ft_strlen(s))
		return (substring);
	while (i++ < start)
		s++;
	i = 0;
	ps = (char *) s;
	/*
	while (llock-- && *ps)
		substring[i++] = *ps++;
	*/
	ft_strlcpy(substring, ps, llock);
	return (substring);
}
/*
int main (void)
{
	char *str = ft_substr("i just want this part #############", 5, 20);
	printf("main: |%s|\n", str);
	return (0);
}
*/