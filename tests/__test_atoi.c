/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __test_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:06:30 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/03 14:24:39 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str);

int main()
{
	printf("------------\n----ATOI----\n------------\n");
	int i = 0;
	char table[18][41] = {"0", "-10", "+30", "--150", "++190", "-2147483647", "+2147483647", "-21474836470", "21474836470", " 4", " 5e7", " 7 9", " - 5", " + 6", "-99999999999999999999999999", "99999999999999999999999999", "999999999999999999", "-999999999999999999"};

	while (table[i] && i < 18)
	{
		int n_atoi = atoi(table[i]);
		int n_ftatoi = ft_atoi(table[i]);
		(n_atoi == n_ftatoi) ? printf("OK (%s) -> %d \n", table[i], n_ftatoi): printf("[ERROR] (%s) >> atoi(%d) != ft_atoi(%d)\n", table[i], n_atoi, n_ftatoi);
		i++;
	}
	return (0);
}