/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:27:34 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/05 13:22:56 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char		*p;
	unsigned char	cc;

	cc = (unsigned char) c;
	p = s;
	while (*s)
		s++;
	while (s >= p)
	{
		if (*s == cc)
			return ((char *) s);
		s--;
	}
	return (0);
}
