/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:26:41 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/27 16:55:28 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_status	*new_status(void)
{
	t_status	*status;

	status = malloc(sizeof(t_status) * 1);
	if (!status)
		return (NULL);

	status->buffer[BUFFER_SIZE] = '\0';
	status->cut = NULL;
	status->rest = NULL;


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

char	*ft_strjoin_empty(char *s1, char *s2, int do_free)
{
	char	*output;
	size_t	len;
	size_t	i;
	size_t	s1i;
	size_t	s2i;

	i = 0;
	s1i =0;
	s2i =0;
	len = ft_strlen(s1) + ft_strlen(s2);
	output = malloc(sizeof(char) * len + 1);
	if (!output)
		return (NULL);
	while (i < len)
	{
		if (i < ft_strlen(s1))
			output[i] = s1[s1i++];
		else
			output[i] = s2[s2i++];
		i++;
	}
	if(s1 != NULL && do_free)
	{
		free(s1);
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