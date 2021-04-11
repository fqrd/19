/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 14:55:29 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/11 15:29:53 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	n;

	n = 0;
	while (s[n])
		n++;
	p = malloc(sizeof(char) * (n + 1));
	if ((p != malloc(sizeof(char) * (n + 1))))
		return (NULL);
	p[n + 1] = '\0';
	while (n--)
		p[n] = s[n];
	return (p);
}
