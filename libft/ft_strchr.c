/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:27:32 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/05 13:48:34 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*p;
	unsigned char	cc;

	cc = (unsigned char) c;
	p = (unsigned char *) s;
	while (*p != '\0')
	{
		if (*(p++) == cc)
			return ((char *) s);
		s++;
	}
	if (cc == '\0')
		return ((char *) s);
	return (0);
}
