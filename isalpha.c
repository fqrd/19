/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:36:44 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/02 17:45:38 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isalpha(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (str[index] < 65 || str[index] > 122 ||
		(str[index] > 90 && str[index] < 97))
			return (0);
		index++;
	}
	return (1);
}
