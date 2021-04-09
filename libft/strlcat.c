/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:35:06 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/09 16:23:04 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
size_t	ft_strlen(const char *str);

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		destlen;
	size_t		srclen;
	long		sizeleft;
	size_t		index;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	sizeleft = size - destlen;
	if (sizeleft <= 0)
		return (srclen + destlen + sizeleft);
	sizeleft--;
	index = destlen;
	while (*src != '\0')
	{
		if (sizeleft > 0)
		{
			dest[index] = *src;
			sizeleft--;
			index++;
		}
		src++;
	}
	dest[index] = '\0';
	return (srclen + destlen);
}
