/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:33:58 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/22 15:55:54 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*first;
	char	*second;
	char	*output;
	size_t	lfirst;
	size_t	lsecond;
	size_t i;

	if (!s1 || !s2)
		return (NULL);

	i = 0;
	first = (char *) s1;
	second = (char *) s2;
	lfirst = ft_strlen(first);
	lsecond = ft_strlen(second);
	output = malloc(sizeof(char) * (lfirst + lsecond + 1));
	if (!output)
		return (NULL);
	while (i < (lfirst + lsecond))
	{
		if (i < lfirst)
			output[i] = *first++;
		else
			output[i]= *second++;
		i++;
	}
	output[i] = '\0';
	return (output);
}

