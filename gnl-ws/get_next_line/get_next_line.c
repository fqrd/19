/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:26:35 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/29 20:55:47 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	find_char(t_list *s, char c)
{
	while (s->buffer[s->end])
	{
		if (s->buffer[s->end] == c)
			return ;
		s->end++;
	}
	s->eob = 1;
	return ;
}

static int	end_of_line(t_list *s, char **line)
{
	*line = substrjoin(s, s->start, s->end);
	if (!*line)
		return (-1);
	s->start = ++s->end;
	return (1);
}

static int	end_of_buffer(t_list *s)
{
	s->rest = substrjoin(s, s->start, s->end);
	if (!s->rest)
		return (0);
	s->populated = 0;
	return (1);
}

static int	end_of_file(t_list *s, char **line)
{
	if (!s->rest)
	{
		*line = malloc(sizeof(char) * 1);
		if (!*line)
			return (-1);
		*line[0] = '\0';
	}
	else
	{
		*line = substrjoin(s, 0, 0);
		if (!*line)
			return (-1);
		s->rest = NULL;
	}
	return (0);
}

static int	freer_the_almighty(t_list *s, int return_value)
{
	if (s)
	{
		if (s->rest != NULL)
		{
			free(s->rest);
			s->rest = NULL;
		}
		if (s->cut != NULL)
		{
			free(s->cut);
			s->cut = NULL;
		}
		if (s->buffer != NULL)
		{
			free(s->buffer);
			s->buffer = NULL;
		}
		if (s != NULL)
		{
			free(s);
			s = NULL;
		}
	}
	return (return_value);
}

int	get_next_line(int fd, char **line)
{
	static t_list	*s;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!s)
	{
		s = new_status(s);
		if (!s)
			return (-1);
	}
	while (1)
	{
		if (s->populated)
		{
			find_char(s, '\n');
			if (!s->eob)
				return (freer_the_almighty(s, end_of_line(s, &*line)));
			else
			{
				if (!end_of_buffer(s))
					return (freer_the_almighty(s, -1));
			}
		}
		else
		{
			ft_bzero(s->buffer, BUFFER_SIZE);
			s->read = read(fd, s->buffer, BUFFER_SIZE);
			if (s->read < 0)
				return (freer_the_almighty(s, -1));
			if (s->read == 0)
			{
				return (freer_the_almighty(s, end_of_file(s, &*line)));
			}
			s->start = 0;
			s->end = 0;
			s->eob = 0;
			s->populated = 1;
			s->read = -1;
		}
	}
	return (freer_the_almighty(s, -1));
}
