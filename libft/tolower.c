/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolower.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:38:05 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/03 14:45:49 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c);

int	ft_tolower(int c)
{
	unsigned char ch;
	ch = (unsigned char) c;
	if (ch >= 'A' && ch <= 'Z')
		ch = ch + 32;
	return (ch);
}