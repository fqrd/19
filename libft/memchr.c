/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:27:19 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/02 13:49:08 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	cc;

	cc = (unsigned char) c;
	p = (unsigned char *) s;
	while (n)
	{
		if (*p == cc)
			return ((void *) p);
		p++;
		n--;
	}
	return (NULL);
}
