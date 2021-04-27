/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:36:20 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/27 15:36:53 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putchar_fd(char c, int fd)
{
	unsigned char cc;

	cc = (unsigned char) c;
	if (!cc)
		return (NULL);

	if (fd > -1)
	{
		write(fd, &cc, 1);
	}
	close(fd);
}
