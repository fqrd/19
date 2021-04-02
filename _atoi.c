/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:33:42 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/02 17:33:44 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	loop_numbers(char *str, int dash, int nbr)
{
	while (*str >= 48 && *str <= 57)
	{
		nbr *= 10;
		nbr += *str - '0';
		str++;
	}
	if (dash % 2 != 0)
		nbr *= -1;
	return (nbr);
}

int	loop_math_symbols(char *str, int dash, int nbr)
{
	while (*str == 45 || *str == 43)
	{
		if (*str == 45)
			dash++;
		str++;
	}
	nbr = (loop_numbers(str, dash, nbr));
	return (nbr);
}

int	ft_isspace(char *str, int nbr)
{
	while (*str == '\t' || *str == '\n' || *str == '\v' ||
	*str == '\f' || *str == '\r' || *str == ' ')
	{
		str++;
	}
	nbr = (loop_math_symbols(str, 0, nbr));
	return (nbr);
}

int	ft_atoi(char *str)
{
	return (ft_isspace(str, 0));
}

#include <stdio.h>
int main()
{
	printf("%d \n", ft_atoi("    ----+---++4984ss9z88854zdazd%%-6514&éçà'èé(§à89"));
}