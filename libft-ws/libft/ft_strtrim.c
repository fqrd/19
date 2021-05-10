/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:34:25 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/05 17:47:59 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_char(char c, char *test)
{
	while (*test)
	{
		if ((unsigned char) *test++ == (unsigned char) c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	char	*output;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && check_char((char) s1[i], (char *) set))
		i++;
	start = i;
	i = ft_strlen(s1) - 1;
	while (i > 0 && check_char((char) s1[i], (char *) set))
		i--;
	if (i >= start && ft_strlen(s1) > 0)
		return (ft_substr(s1, start, (i - start) + 1));
	output = malloc(sizeof(char) * 1);
	if (!output)
		return (NULL);
	output[0] = '\0';
	return (output);
}
