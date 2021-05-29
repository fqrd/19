/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:26:41 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/29 20:43:47 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*new_status(t_list *s)
{
	s = malloc(sizeof(t_list) * 1);
	if (!s)
		return (NULL);
	s->buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!s->buffer)
		return (NULL);
	s->buffer[BUFFER_SIZE] = '\0';
	s->cut = NULL;
	s->rest = NULL;
	s->start = 0;
	s->end = 0;
	s->read = -1;
	s->eob = 0;
	s->populated = 0;
	return (s);
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
	if (s1 != NULL && do_free)
	{
		free(s1);
		s1 = NULL;
	}
	output[i] = '\0';
	return (output);
}

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = (char *) s;
	while (n-- > 0)
		*p++ = '\0';
}

char	*substrjoin(t_list *s, size_t start, size_t end)
{
	char	*output;
	size_t	index;
	size_t	restlen;
	size_t	len;

	index = 0;
	restlen = 0;
	len = end - start;
	if (s->rest)
	{
		restlen = ft_strlen(s->rest);
	}
	output = malloc(sizeof(char) * (restlen + len + 1));
	if (!output)
		return (NULL);
	while (index < restlen + len)
	{
		if (s->rest && s->rest[index] != '\0' && index < restlen)
		{
			output[index] = s->rest[index];
		}
		else
		{
			if (s->buffer && s->buffer[start] && start < end)
			{
				output[index] = s->buffer[start++];
			}
		}
		index++;
	}
	output[index] = '\0';
	if (s->rest)
	{
		free(s->rest);
		s->rest = NULL;
	}
	return (output);
}
