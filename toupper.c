/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:37:45 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/02 17:48:08 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*toupper(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (str[index] >= 'a' && str[index] <= 'z')
			str[index] = str[index] - 32;
		index++;
	}
	return (str);
}