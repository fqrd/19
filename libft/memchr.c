/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:27:19 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/20 14:33:14 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char		*p;
	unsigned char	cc;

	cc = (unsigned char) c;
	p = s;
	while (n)
	{
		if (*p == cc)
			return ((void *) p);
		p++;
		n--;
	}
	return (NULL);
}
