/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:27:27 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/11 12:40:44 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;
	int			dir;

	s = (char *)src;
	d = (char *)dest;
	dir = 0;
	if (s + n >= d)
	{
		dir = 1;
		s = s + n;
		d = d + n;
	}
	while (n)
	{
		if(dir)
		{
			*d = *s--;
			d--;
		}
		else
		{
			*d = *s++;
			d++;
		}
		n--;
	}
	return (dest);
}
