/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:57:57 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/31 16:37:30 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	mfree(t_list **s, int return_value)
{
	if (*s)
	{
		if ((*s)->rest != NULL)
		{
			free((*s)->rest);
			(*s)->rest = NULL;
		}
		if ((*s)->buffer != NULL)
		{
			free((*s)->buffer);
			(*s)->buffer = NULL;
		}
		if (*s != NULL)
		{
			free(*s);
			*s = NULL;
		}
	}
	return (return_value);
}

static int	action_on_buffer(t_list **s, char **line)
{
	find_char(&*s, '\n');
	if (!(*s)->eob)
	{
		*line = substrjoin(&*s, (*s)->start, (*s)->end, ft_strlen((*s)->rest));
		if (!*line)
			return (mfree(&*s, -1));
		(*s)->start = ++(*s)->end;
		return (1);
	}
	else
	{
		(*s)->rest = substrjoin(&*s, (*s)->start, (*s)->end, ft_strlen((*s)->rest));
		if (!(*s)->rest)
			return (mfree(&*s, -1));
		(*s)->populated = 0;
		return (0);
	}
}

static int	reset(t_list **s)
{
	(*s)->start = 0;
	(*s)->end = 0;
	(*s)->eob = 0;
	(*s)->populated = 1;
	(*s)->read = -1;
	return (1);
}

static int	last_buffer(int fd, t_list **s, char **line)
{
	ft_bzero((*s)->buffer, BUFFER_SIZE);
	(*s)->read = read(fd, (*s)->buffer, BUFFER_SIZE);
	if ((*s)->read > 0)
		return (reset(&*s));
	else if ((*s)->read == 0)
	{
		if (!(*s)->rest)
		{
			*line = malloc(sizeof(char) * 1);
			if (!*line)
				return (mfree(&*s, -1));
			*line[0] = '\0';
		}
		else
		{
			*line = substrjoin(&*s, 0, 0, ft_strlen((*s)->rest));
			if (!*line)
				return (mfree(&*s, -1));
			(*s)->rest = NULL;
		}
		return (mfree(&*s, 0));
	}
	else
		return (mfree(&*s, -1));
}

int	get_next_line(int fd, char **line)
{
	static t_list	*s;
	int				res;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!s)
		s = new_status(s);
	while (s)
	{
		if (s->populated)
		{
			res = action_on_buffer(&s, &*line);
			if (res != 0)
				return (res);
		}
		else
		{
			res = last_buffer(fd, &s, &*line);
			if (res < 1)
				return (res);
		}
	}
	return (mfree(&s, -1));
}
