/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:27:27 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/12 12:53:34 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stddef.h>
#include <stdio.h>
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*psrc = (char *) src;
	char	*pdest = (char *) dest;
	
	if (psrc < pdest)
	{
		psrc = psrc + (n - 1);
		pdest = pdest + (n - 1);
		while (n--)
			*(pdest)-- = *(psrc)--;
	}
	else
	{
		while(n--)
			*(pdest)++ = *(psrc)++;
	}
	if( !dest && !src)
		return (NULL);
	
	return (dest);
}

int main()
{
	printf("%p\n",ft_memmove(NULL, NULL, 12));
	printf("%p\n", memmove(NULL, NULL, 12));
	return (0);
}

