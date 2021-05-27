/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:26:41 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/27 11:18:27 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_status	*new_status(void)
{
	t_status	*status;

	status = malloc(sizeof(t_status) * 1);
	if (!status)
		return (NULL);
	status->buffer[BUFFER_SIZE + 1] = '\0';
	status->line = "\0";
	status->cut = "\0";
	status->rest = "\0";

	status->start = 0;
	status->end = 0;
	status->read = 0;
	status->eob = 0;
	status->populated = 0;
	return (status);
}


size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	if (!str)
		return (index);
	while (str[index])
		index++;
	return (index);
}


size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	index;
	size_t	size_src;

	if (!dest && !src)
		return (0);
	index = 0;
	size_src = ft_strlen(src);
	if (size_src < size)
		size = size_src + 1;
	while (index < size)
	{
		if (index + 1 == size)
			dest[index] = '\0';
		else
			dest[index] = src[index];
		index++;
	}
	return (size_src);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*first;
	char	*second;
	char	*output;
	size_t	len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	first = (char *) s1;
	second = (char *) s2;
	len = ft_strlen(s1) + ft_strlen(s2);
	output = malloc(sizeof(char) * len + 1);
	if (!output)
		return (NULL);
	while (i < len)
	{
		if (i < ft_strlen(s1))
			output[i] = *first++;
		else
			output[i] = *second++;
		i++;
	}
	output[i] = '\0';
	return (output);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ps;
	char			*substring;
	size_t			llock;

	llock = 0;
	ps = (char *) s;
	if (!s || len == 0 || start > ft_strlen(s))
	{
		substring = malloc(sizeof(char) * 1);
		if (!substring)
			return (NULL);
		ft_strlcpy(substring, "\0", 1);
		return (substring);
	}
	while (start + llock < ft_strlen(s) && llock < len)
		llock++;
	substring = malloc(sizeof(char) * (llock + 1));
	if (!substring)
		return (NULL);
	ft_strlcpy(substring, ps + start, llock + 1);
	return (substring);
}

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = (char *) s;
	while (n-- > 0)
		*p++ = '\0';
}