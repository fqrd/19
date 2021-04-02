/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:39:34 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/02 17:39:35 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *src)
{
	unsigned int index;

	index = 0;
	while (src[index])
		index++;
	return (index);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int index;
	unsigned int size_src;

	index = 0;
	size_src = ft_strlen(src);
	if (size_src < size)
		size = size_src + 1;
	while (index < size)
	{
		if (index + 1 == size)
			dest[index] = '\0';
		else
			dest[index] = src[index];
		index++;
	}
	return (size_src);
}
