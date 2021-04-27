/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:39:20 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/27 14:37:44 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char *nstr; 
	if (fd > -1)
	{
		nstr = ft_itoa(n);
		while (*nstr)
		{
			write(fd, nstr, 1);	
			nstr++;
		}
	}
	close (fd);
}
