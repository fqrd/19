/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:27:16 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/15 17:05:50 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*pdest;
	unsigned char	*psrc;

	i = 0;
	psrc = (unsigned char *) src;
	pdest = (unsigned char *) dest;
	while (n--)
	{	
		pdest[i] = psrc[i];
		if (psrc[i] == (unsigned char) c)
		{	
			pdest[++i] = '\0';
			return ((void *)(dest + i));
		}
		i++;
	}
	return (NULL);
}
