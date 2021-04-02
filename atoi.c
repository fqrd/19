/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:33:42 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/02 19:58:23 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str);

static int	loop_numbers(char *str, int dash, int nbr)
{
	while (*str >= 48 && *str <= 57)
	{
		nbr *= 10;
		nbr += *str - '0';
		str++;
	}
	if (dash == 1)
		nbr *= -1;
	return (nbr);
}

static int	loop_math_symbols(char *str, int negative, int nbr)
{
	if (*str == 45)
	{
		negative = 1;
		nbr = loop_numbers(++str, negative, nbr);
	}
	else if (*str == 43)
	{
		nbr = loop_numbers(++str, negative, nbr);
	}
	else
	{
		nbr = loop_numbers(str, negative, nbr);
	}
	return (nbr);
}

static int	ft_isspace(char *str, int nbr)
{
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	nbr = (loop_math_symbols(str, 0, nbr));
	return (nbr);
}

int	ft_atoi(char *str)
{
	return (ft_isspace(str, 0));
}
