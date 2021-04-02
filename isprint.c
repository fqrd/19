/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:38:28 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/02 18:23:59 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	isprint(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (str[index] < 32 || str[index] > 127)
			return (0);
		index++;
	}
	return (1);
}
