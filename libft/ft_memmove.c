/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:27:27 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/10 16:05:18 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*psrc;
	char	*pdest;

	if (!dest && !src)
		return (NULL);
	if (dest == src)
		return (dest);
	psrc = (char *) src;
	pdest = (char *) dest;
	if (psrc < pdest)
	{
		psrc = psrc + (n - 1);
		pdest = pdest + (n - 1);
		while (n--)
			*(pdest)-- = *(psrc)--;
	}
	else
	{
		while (n--)
			*(pdest)++ = *(psrc)++;
	}
	return (dest);
}
