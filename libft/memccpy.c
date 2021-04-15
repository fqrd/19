/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:27:16 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/15 17:00:04 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

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
		printf("c: %c\n", psrc[i]);
		pdest[i] = psrc[i];
		if (psrc[i] == (unsigned char) c)
		{	
			pdest[++i] = '\0';
			printf("res: %s\n", pdest);
			return ((void *)(dest + i));
		}
		i++;
	}
	return (NULL);
}
