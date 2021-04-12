/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:27:27 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/11 19:19:06 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*_src;
	char	*_dest;
	int		direction;

	_src = (char *)src;
	_dest = (char *)dest;
	direction = 0;
	if (_src + n >= _dest)
	{
		direction = 1;
		_src = _src + n;
		_dest = _dest + n;
	}
	while (n)
	{
		if(direction)
		{
			*_dest = *_src--;
			_dest--;
		}
		else
		{
			*_dest = *_src++;
			_dest++;
		}
		n--;
	}
	return (dest);
}
