/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:30:37 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/19 14:58:37 by fcaquard         ###   ########.fr       */
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
	unsigned int	i;

	i = 0;
	substring = malloc(sizeof(char *) * (len + 1));
	if(!substring || s == NULL || len == 0)
		return (NULL);
	if(start >= ft_strlen(s))
		return (substring);
	while (i++ < start)
		s++;
	i = 0;
	ps = (char *) s;
	while (len-- && *ps)
	{
		substring[i++] = *ps++;
	}
	substring[i] = '\0';
	return (substring);
}

