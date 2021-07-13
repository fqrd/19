/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:00:17 by fcaquard          #+#    #+#             */
/*   Updated: 2021/07/13 14:34:26 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*mfree(t_list **s)
{
	if (*s)
	{
		if ((*s)->rest != NULL)
			free((*s)->rest);
		if ((*s)->buffer != NULL)
			free((*s)->buffer);
		(*s)->rest = NULL;
		(*s)->buffer = NULL;
		if (*s != NULL)
			free(*s);
		*s = NULL;
	}
	return (NULL);
}

static char *action_on_buffer(t_list **s)
{
	if (find_char(&*s, '\n'))
	{
		(*s)->line = substrjoin(&*s, (*s)->start, ++(*s)->end,
				ft_strlen((*s)->rest));
		if (!(*s)->line)
			return (mfree(&*s));
		(*s)->start = (*s)->end;
		return ((*s)->line);
	}
	else
	{
		if ((*s)->start != (*s)->end)
		{
			(*s)->rest = substrjoin(&*s, (*s)->start,
					(*s)->end, ft_strlen((*s)->rest));
			if (!(*s)->rest)
				return (mfree(&*s));
		}
		(*s)->populated = 0;
		return ("1");
	}
}

static char *load_buffer(int fd, t_list **s)
{
	int	res;

	ft_bzero((*s)->buffer, BUFFER_SIZE);
	res = read(fd, (*s)->buffer, BUFFER_SIZE);
	if (res > 0)
	{
		(*s)->start = 0;
		(*s)->end = 0;
		(*s)->populated = 1;
		return ("1");
	}
	else if (res == 0 && (*s)->rest != NULL)
	{
		(*s)->line = substrjoin(&*s, 0, 0,
				ft_strlen((*s)->rest));
		if (!(*s)->line)
			return (mfree(&*s));
		return ((*s)->line);
	}
	return (mfree(&*s));
}

char	*get_next_line(int fd)
{
	static t_list	*s[1024];
	char			*res;

	res = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!s[fd])
		s[fd] = new_status(s[fd]);
	s[fd]->line = NULL;
	while (s[fd])
	{
		if (s[fd]->populated)
		{
			res = action_on_buffer(&s[fd]);
			if (res == NULL || s[fd]->line != NULL)
				return (res);
		}
		else
		{
			res = load_buffer(fd, &s[fd]);
			if (res == NULL || s[fd]->line != NULL)
				return (res);
		}
	}
	return (mfree(&s[fd]));
}
