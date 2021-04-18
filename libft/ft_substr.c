/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:30:37 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/15 19:20:42 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *p = (char *) s;
	char *substring;
	unsigned int i = 0;
	// size_t slen;

	// slen = ft_strlen(p);
	// if (slen < start + len || slen == 0 || len == 0)
	// 	return ("STRING NULL RETURNED");

	substring = malloc(sizeof(char *) * (len));
	if(!substring)
		return (NULL);

	while (i++ < start)
		p++;
	i = 0;
	while (i < len && *p)
	{
		substring[i] = *p;
		p++;
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

