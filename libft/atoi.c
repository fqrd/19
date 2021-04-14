/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:35:53 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/14 13:35:33 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long	nbr;
	long long	add;
	int			sign;

	nbr = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == 45)
		sign = -1;
	if (*str == 43 || *str == 45)
		str++;
	while (*str >= 48 && *str <= 57)
	{
		add = 10 * nbr + (*str - '0');
		if (add > nbr)
			nbr = add;
		str++;
	}
	if (add < nbr && sign == 1)
		return (-1);
	if (add < nbr && sign == -1)
		return (0);
	nbr = nbr * sign;
	return (nbr);
}
