/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:34:24 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/02 17:34:25 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int index;

	index = 0;
	while (index < n && (s1[index] || s2[index]))
	{
		if (s1[index] != s2[index])
			return (s1[index] - s2[index]);
		index++;
	}
	return (0);
}


#include <stdio.h>
#include <string.h>

int main(void)
{
	char s1[] = "/0abcdefm";
	char s2[] = "/0abcdef";
	printf("%d\n",ft_strncmp(s1,s2, 50));
	printf("%d\n",strncmp(s1,s2, 50));
}