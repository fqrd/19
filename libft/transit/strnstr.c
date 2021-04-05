/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 14:31:47 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/05 15:23:50 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*pb;
	const char	*pl;
	const char	*start;

	pb = big;
	pl = little;
	if (*little == '\0')
		return ((char *) big);
	while (*big != '\0' && len - (big - pb) > 0)
	{
		if (*big == *little)
		{
			start = big;
			while (*big == *little && *big != '\0' && len - (big - pb) > 0)
			{
				if (*(++little) == '\0')
					return ((char *) start);
				big++;
			}
			big = start;
			little = pl;
		}
		big++;
	}
	return (0);
}
