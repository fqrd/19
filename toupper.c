/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:37:45 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/03 14:40:35 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
int	ft_toupper(int c);

int ft_toupper(int c)
{
	unsigned char ch;
	ch = (unsigned char) c;
	if (ch >= 'a' && ch <= 'z')
		ch = ch - 32;
	return (ch);
}