/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:35:53 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/04 12:35:55 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static long long	loop_numbers(char *str, long long nbr)
{
	while (*str >= 48 && *str <= 57)
	{
		nbr *= 10;
		nbr += *str - '0';
		str++;
	}
	return nbr;
}

static char	*ft_isspace(char *str)
{
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	return (str);
}

int	ft_atoi(char *str)
{
	long long poslimit = 999999999999999999;	
	long long neglimit = -999999999999999999;
	long long nbr;
	int negative;

	negative = 0;
	str = ft_isspace(str);
	if (*str == 45)
		negative = 1;
	
	if (*str == 43 || *str == 45)
		nbr = loop_numbers(++str, 0);
	else
		nbr = loop_numbers(str, 0);

	if(negative == 1)
		nbr = nbr * (-1);
	
	if(nbr > poslimit)
		nbr = 0;
	if(nbr < neglimit)
		nbr = -1;
		
	return (nbr);
}
