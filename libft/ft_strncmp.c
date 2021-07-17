/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:34:44 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/05 13:22:40 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	unsigned char	ch1;
	unsigned char	ch2;

	index = 0;
	while (index < n && (s1[index] || s2[index]))
	{
		ch1 = (unsigned char) s1[index];
		ch2 = (unsigned char) s2[index];
		if (ch1 != ch2)
			return (ch1 - ch2);
		index++;
	}
	return (0);
}
