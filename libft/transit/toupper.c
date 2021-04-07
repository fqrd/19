/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:36:28 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/07 15:36:54 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	unsigned char	ch;

	ch = (unsigned char) c;
	if (ch >= 'a' && ch <= 'z')
		ch = ch - 32;
	return (ch);
}
