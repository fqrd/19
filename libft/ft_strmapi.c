/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:35:53 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/05 13:22:38 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ps;
	int		i;
	char	*output;

	if (!s || !(*f))
		return (NULL);
	ps = (char *) s;
	i = 0;
	output = malloc (sizeof(char) * ft_strlen(ps) + 1);
	if (!output)
		return (NULL);
	while (ps[i] != '\0')
	{
		output[i] = (*f)((unsigned int) i, (char) ps[i]);
		i++;
	}
	output[i] = '\0';
	return (output);
}
