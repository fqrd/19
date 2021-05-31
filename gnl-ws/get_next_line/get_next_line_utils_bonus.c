/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:58:06 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/31 16:19:45 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*new_status(t_list *s)
{
	s = malloc(sizeof(t_list) * 1);
	if (!s)
		return (NULL);
	s->buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!s->buffer)
		return (NULL);
	s->buffer[BUFFER_SIZE] = '\0';
	s->rest = NULL;
	s->start = 0;
	s->end = 0;
	s->read = -1;
	s->eob = 0;
	s->populated = 0;
	return (s);
}

void	find_char(t_list **s, char c)
{
	while ((*s)->buffer[(*s)->end])
	{
		if ((*s)->buffer[(*s)->end] == c)
			return ;
		(*s)->end++;
	}
	(*s)->eob = 1;
	return ;
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

void	ft_bzero(void *buff, size_t len)
{
	char	*p;

	p = (char *) buff;
	while (len-- > 0)
		*p++ = '\0';
}

char	*substrjoin(t_list **s, size_t start, size_t end, size_t restlen)
{
	char	*output;
	size_t	index;
	size_t	len;

	index = 0;
	len = end - start;
	output = malloc(sizeof(char) * (restlen + len + 1));
	if (!output)
		return (NULL);
	while (index < restlen + len)
	{
		if ((*s)->rest && (*s)->rest[index] != '\0' && index < restlen)
			output[index] = (*s)->rest[index];
		if ((*s)->buffer && (*s)->buffer[start] && start < end && index >= restlen)
			output[index] = (*s)->buffer[start++];
		index++;
	}
	output[index] = '\0';
	if ((*s)->rest)
	{
		free((*s)->rest);
		(*s)->rest = NULL;
	}
	return (output);
}
