/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:27:16 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/12 14:41:26 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	char		*pdest;
	char		*psrc;

	i = 0;
	psrc = (char *) src;
	pdest = (char *) dest;
	while (n--)
	{
		pdest[i] = psrc[i];
		if (psrc[i] == c)
		{
			pdest[i + 1] = '\0';	
			return (dest);
		}
		i++;
	}
	return (dest);
}
