/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:00:17 by fcaquard          #+#    #+#             */
/*   Updated: 2021/07/11 14:19:54 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void *mfree(t_list **s)
{
	if (*s)
	{
		if ((*s)->rest != NULL)
			free((*s)->rest);
		if ((*s)->buffer != NULL)
			free((*s)->buffer);
		(*s)->buffer = NULL;
		(*s)->rest = NULL;
		if (*s != NULL)
			free(*s);
		*s = NULL;
	}
	return (NULL);
}

static void	reinitialize_variables(t_list **s)
{
	(*s)->start = 0;
	(*s)->end = 0;
	(*s)->populated = 1;
}

char	*get_next_line(int fd)
{
	static t_list	*s[1024];
	int				res;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!s[fd])
		s[fd] = new_status(s[fd]);
	while (s[fd])
	{
		if (s[fd]->populated)
		{
			if (find_char(&s[fd], '\n'))
			{
				s[fd]->line = substrjoin(&s[fd], s[fd]->start, s[fd]->end, ft_strlen(s[fd]->rest));
				if (!s[fd]->line)
					return (mfree(&s[fd]));
				s[fd]->start = ++s[fd]->end;
				return (s[fd]->line);
			}
			else
			{
				s[fd]->rest = substrjoin(&s[fd], s[fd]->start,
						s[fd]->end, ft_strlen(s[fd]->rest));
				if (!s[fd]->rest)
					return (mfree(&s[fd]));
				s[fd]->populated = 0;
			}
		}
		else
		{
			ft_bzero(s[fd]->buffer, BUFFER_SIZE);
			res = read(fd, s[fd]->buffer, BUFFER_SIZE);
			if (res > 0)
			{
				reinitialize_variables(&s[fd]);
			}
			else if (res == 0 && s[fd]->rest != NULL)
			{
				s[fd]->line = substrjoin(&s[fd], 0, 0, ft_strlen(s[fd]->rest));
				if (!s[fd]->line)
					return (mfree(&s[fd]));
				return (s[fd]->line);
			}
			else
			{
				return (mfree(&s[fd]));
			}
		}
	}
	return (mfree(&s[fd]));
}



int main(void)
{
	
    int fd;
    char *source[]= {
		// "./tests/one_char",
		// "./tests/42_no_nl",
    //    "./tests/43_no_nl",
       "./tests/alternate_line_nl_no_nl",
    //    "./tests/big_line_no_nl",
    //    "./tests/empty",
    //    "./tests/multiple_line_with_nl",
    //    "./tests/nl",
    //    "./tests/t_small.txt",
    //    "./tests/41_with_nl",
    //    "./tests/42_with_nl",
    //    "./tests/43_with_nl",
    //    "./tests/alternate_line_nl_with_nl",
    //    "./tests/big_line_with_nl",
    //    "./tests/multiple_line_no_nl",
    //    "./tests/multiple_nlx5",
    //    "./tests/test_test",
	   "\0"
	};
    #ifdef BUFFER_SIZE
		int i = 0;
		while(source[i][0])
		{
			printf("\n\n[testing: %s]\n\n", source[i]);
			fd = open(source[i], O_RDWR);
			if (fd > -1)
			{
				// printf("%s",get_next_line(fd));
				char *res;
				while (res != NULL)
				{
					res = get_next_line(fd);
					printf("|%s|\n", res);
				}
				close(fd);
			}
			i++;
		}
    #endif
	
    return (0);
}