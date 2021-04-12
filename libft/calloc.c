/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard </var/mail/fcaquard>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:38:22 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/12 15:51:38 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
void	*ft_calloc(size_t count, size_t size)
{
	char *p;
	size_t m;
	size_t i;

	i = 0;
	m = size * count;
	p = malloc(m);
	if (!p)
		return (NULL);
	p[i] = '\0';
	while(++i < m)
		p[i] = '\0';
	return (p);
}

