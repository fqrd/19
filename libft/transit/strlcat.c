/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:35:06 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/04 12:35:08 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define T_SIZE unsigned long

static unsigned long	ft_strlen(const char *str)
{
	unsigned long	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

T_SIZE	ft_strlcat(char *dest, const char *src, const T_SIZE size)
{
	T_SIZE		destlen;
	T_SIZE		srclen;
	long		sizeleft;
	T_SIZE		index;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	sizeleft = size - destlen;
	if (sizeleft <= 0)
		return (srclen + destlen + sizeleft);
	sizeleft--;
	index = destlen;
	while (*src != '\0')
	{
		if (sizeleft > 0)
		{
			dest[index] = *src;
			sizeleft--;
			index++;
		}
		src++;
	}
	dest[index] = '\0';
	return (srclen + destlen);
}
