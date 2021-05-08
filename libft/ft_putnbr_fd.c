/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:39:20 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/06 15:02:24 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recc_write(int n, int fd)
{
	if (n > -10 && n < 0)
		ft_putchar_fd('-', fd);
	if (n <= -10 || n >= 10)
	{
		recc_write(n / 10, fd);
		n = n % 10;
	}
	if (n < 0)
		n *= (-1);
	ft_putchar_fd(n + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd > -1)
		recc_write(n, fd);
}
