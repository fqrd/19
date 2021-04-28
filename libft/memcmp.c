/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:27:23 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/28 15:23:09 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*q;

	p = (unsigned char *) s1;
	q = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (n && (*p++ == *q++))
		n--;
	return (p[-1] - q[-1]);
}
