/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:21:04 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/05 13:21:52 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*pdest;
	unsigned char	*psrc;
	unsigned char	pc;

	i = 0;
	pc = (unsigned char) c;
	psrc = (unsigned char *) src;
	pdest = (unsigned char *) dest;
	while (i < n)
	{	
		pdest[i] = psrc[i];
		if (pdest[i] == pc)
			return ((void *) dest + (i + 1));
		i++;
	}
	return ((void *) NULL);
}
