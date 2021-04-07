/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:27:19 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/06 19:03:59 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*p;

	p = s;
	while (n)
	{
		if (*p == c)
			return ((void *) p);
		p++;
		n--;
	}
	return (NULL);
}
