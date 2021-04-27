/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:38:55 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/27 15:38:06 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return (void);
	if (fd > -1)
	{
		while (*s)
		{
			write (fd, s, 1);
			s++;
		}
		write (fd, "\n", 1);
	}
	close (fd);
}
