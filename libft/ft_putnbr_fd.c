/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:39:20 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/06 13:56:20 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static void	recc_write(int n, int fd)
{
	if ((n >= 0 && n < 10) || (n < 0 && n > -10))
	{
		if (n < 0)
		{
			n *= (-1);
			ft_putchar_fd('-', fd);
		}
		ft_putchar_fd(n + '0', fd);
	}
	else
	{
		recc_write(n / 10, fd);
		n = n % 10;
		if (n < 0)
			n *= (-1);
		ft_putchar_fd(n + '0', fd);
	}
}*/

static 	int	count_digits(int n)
{
	int	size;

	size = 1;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		size++;
	}
	return (size);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd > -1)
		write(fd, ft_itoa(n), count_digits(n));
}
