/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:30:37 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/21 17:14:13 by fcaquard         ###   ########.fr       */
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
	size_t			ml;

	ml = 0;
	i = 0;
	while (start + ml < ft_strlen(s) && ml < len)
		ml++;
	substring = malloc(sizeof(char *) * (ml + 1));
	if(!substring || s == NULL || len == 0)
		return (NULL);
	substring[ml] = '\0';
	if (start > ft_strlen(s))
		return (substring);
	while (i++ < start)
		s++;
	i = 0;
	ps = (char *) s;
	while (ml-- && *ps)
		substring[i++] = *ps++;
	return (substring);
}

