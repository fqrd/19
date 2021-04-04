/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:34:53 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/02 17:34:54 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int index;
	unsigned int destlen;
	unsigned int srclen;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	index = 0;
	if (size > destlen)
	{
		while (index < size - 1 && *src)
		{
			if (index >= destlen)
			{
				dest[index] = *src;
				src++;
			}
			index++;
		}
		dest[index] = '\0';
	}
	if (size < destlen)
		return (srclen + size);
	return (destlen + srclen);
}
