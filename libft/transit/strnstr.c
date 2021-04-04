/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 14:31:47 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/04 15:40:13 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(char *str, char *to_find, unsigned long len)
{
	unsigned long	to_find_index;
	unsigned long	index;

	index = 0;
	to_find_index = 0;
	if (!to_find[0])
		return (&str[0]);
	while (str[index] != '\0' && index < len)
	{
		if (str[index] == to_find[0])
		{
			while (to_find[to_find_index] == str[index] && str[index] != '\0')
			{
				if (to_find[to_find_index + 1] == '\0')
					return (&str[index - to_find_index]);
				index++;
				to_find_index++;
			}
			index -= to_find_index;
			to_find_index = 0;
		}
		index++;
	}
	return (0);
}
