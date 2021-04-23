/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:35:11 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/23 13:58:33 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

static char	*to_char(long long value, int size, char *output)
{
	if (value < 10)
	{
		output[size] = value + '0';
		return (output);
	}
	else
	{
		to_char(value / 10, --size, output);
		output[size] = (value % 10) + '0';
	}
	return (output);
}

static char	*below_zero(long long v, int size)
{
	char	*output;
	
	output = malloc(sizeof(char) * (size + 2));
	if (!output)
		return (NULL);
	output[0] = '-';
	to_char(v, size, ++output);
	output[size + 1] = '\0';
	return (output);
}

static char	*above_zero(long long v, int size)
{
	char	*output;

	output = malloc(sizeof(char) * (size + 1));
	if (!output)
		return (NULL);
	to_char(v, size - 1, output);
	output[size] = '\0';
	return (output);
}

char	*ft_itoa(int value)
{
	long long	v;
	int			size;
	char		*output;

	v = (long long) value;
	size = 1;
	while (value > 10 || value < -10)
	{
		value /= 10;
		size++;
	}
	if (v < 0)
		output = below_zero(v*(-1), size);
	else
		output = above_zero(v, size);
	if (!output)
		return (NULL);
	return (output);
}
