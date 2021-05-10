/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:30:37 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/10 16:06:23 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ps;
	char			*substring;
	size_t			llock;

	llock = 0;
	ps = (char *) s;
	if (s && len != 0)
	{
		while (start + llock < ft_strlen(s) && llock < len)
			llock++;
	}
	substring = malloc(sizeof(char) * (llock + 1));
	if (!substring)
		return (NULL);
	if (start > ft_strlen(s) || len == 0 || !s)
		ft_strlcpy(substring, "\0", 1);
	else
		ft_strlcpy(substring, ps + start, llock + 1);
	return (substring);
}
