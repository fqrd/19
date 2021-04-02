/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:37:15 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/02 17:45:31 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (str[index] < 48 || str[index] > 57)
			return (0);
		index++;
	}
	return (1);
}