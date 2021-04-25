/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:33:58 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/25 19:14:23 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*first;
	char	*second;
	char	*output;
	size_t	len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	first = (char *) s1;
	second = (char *) s2;
	len = ft_strlen(first) + ft_strlen(second);
	output = malloc(sizeof(char) * (len + 1));
	if (!output)
		return (NULL);
	while (i < len)
	{
		if (i < ft_strlen(first))
			output[i] = *first++;
		else
			output[i] = *second++;
		i++;
	}
	output[i] = '\0';
	return (output);
}
