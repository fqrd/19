/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:39:20 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/27 15:35:43 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

static void	recc_write(int n, int fd)
{
	if ((n >= 0 && n < 10) || (n < 0 && n > -10))
	{
		if(n < 0)
		{
			n *= (-1);	
			ft_putchar('-', fd);
		}
		ft_putchar(n + '0', fd);
	}
	else
	{
		recc_write(n / 10, fd);
		if (n < 0)
			n *= (-1);
		ft_putchar((n % 10) + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd > -1)
		recc_write(n, fd);
	close (fd);
}

/*
int main(void)
{
	int fd;
	int i = 123456789;
	fd = open("./b", O_WRONLY);
	ft_putnbr_fd(i, fd);
	return (0);
}
*/