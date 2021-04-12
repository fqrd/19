/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 14:55:29 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/12 10:55:19 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	n;
	size_t i;

	n = 0;
	while (s[n])
		n++;
	p = malloc(sizeof(char) * (n + 1));
	if (!p)
		return (NULL);
	p[n] = '\0';
	while (--n >= 0)
		p[i] = s[i];
	return (p);
}
