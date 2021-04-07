/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:27:16 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/06 18:18:29 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	s = src;
	d = dest;
	while (n--)
	{
		d[i] = s[i];
		if (s[i] == c)
			return (dest);
		i++;
	}
	return (dest);
}
