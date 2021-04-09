/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:35:53 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/09 16:18:26 by fcaquard         ###   ########.fr       */
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
	long long	poslimit;
	long long	neglimit;
	long long	nbr;
	int			sign;

	poslimit = 999999999999999999;
	neglimit = -999999999999999999;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == 45)
		sign = -1;
	if (*str == 43 || *str == 45)
		str++;
	while (*str >= 48 && *str <= 57)
	{
		nbr = 10 * nbr + (*str - '0');
		str++;
	}
	nbr = nbr * sign;
	if (nbr > poslimit)
		nbr = 0;
	if (nbr < neglimit)
		nbr = -1;
	return (nbr);
}
