/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:26:41 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/16 15:35:37 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	index;
	
	index = 0;
	if (!str)
		return (index);
	while (str[index])
		index++;
	return (index);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	index;
	size_t	size_src;

	if (!dest && !src)
		return (0);
	index = 0;
	size_src = ft_strlen(src);
	if (size_src < size)
		size = size_src + 1;
	while (index < size)
	{
		if (index + 1 == size)
			dest[index] = '\0';
		else
			dest[index] = src[index];
		index++;
	}
	return (size_src);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		destlen;
	size_t		srclen;
	long		sizeleft;
	size_t		index;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	sizeleft = size - destlen;
	if ((long long) size >= 0 && sizeleft <= 0)
		return (srclen + destlen + sizeleft);
	if ((long long) size < 0)
		sizeleft = srclen + destlen;
	sizeleft--;
	index = destlen;
	while (*src != '\0')
	{
		if (sizeleft-- > 0)
			dest[index++] = *src;
		src++;
	}
	dest[index] = '\0';
	return (srclen + destlen);
}
