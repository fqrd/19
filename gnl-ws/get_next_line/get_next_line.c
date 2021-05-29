/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:26:35 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/29 20:14:55 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
* gcc -Werror -Wextra -Wall -D BUFFER_SIZE=32 get_next_line_utils.c get_next_line.c && ./a.out
*/

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

static	int end_of_line(t_list *s, char **line)
{
	*line = substrjoin(s, s->start, s->end);
	if (!*line)
		return (0);
	s->start = ++s->end;
	// printf("LINE(eol): %p -> |%s|\n", *line,*line);
	return (1);
}

static	int end_of_buffer(t_list *s)
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
			return (0);
		*line[0] = '\0';
	}
	else
	{
		// *line = ft_strjoin_empty(s->rest, NULL, 1);
		*line = substrjoin(s, 0, 0);
		if (!*line)
			return (0);
		s->rest = NULL;
	}
	// printf("LINE(eof): %p ->  |%s|\n", *line,*line);
	return (1);
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
			return(-1);
	}

	while (1)
	{
		if (s->populated)
		{
			find_char(s, '\n');
			if (!s->eob)
			{
				if(!end_of_line(s, &*line))
					return (freer_the_almighty(s, -1));
				return (1);				
			}
			else
			{
				if(!end_of_buffer(s))
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
				if(freer_the_almighty(s, end_of_file(s, &*line)))
				{
					s = NULL;
					return (0);
				}
				return (-1);
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

/*
int main(void)
{
    int fd;
    char *line;
	// char *source;
    char *source[]= {
		// "./tests/42_no_nl",
    //    "./tests/43_no_nl",
    //    "./tests/alternate_line_nl_no_nl",
    //    "./tests/big_line_no_nl",
    //    "./tests/empty",
       "./tests/multiple_line_with_nl",
    //    "./tests/nl",
    //    "./tests/t_small.txt",
    //    "./tests/41_with_nl",
    //    "./tests/42_with_nl",
    //    "./tests/43_with_nl",
    //    "./tests/alternate_line_nl_with_nl",
    //    "./tests/big_line_with_nl",
    //    "./tests/multiple_line_no_nl",
       "./tests/multiple_nlx5",
    //    "./tests/test_test",
	   "\0"
	};
    #ifdef BUFFER_SIZE
		// while (get_next_line(fd, &line) != 0) { ;}
		// source = "./tests/multiple_line_with_nl";
		
		int i = 0;
		while(source[i][0])
		{
			printf("\n\n[%s]\n\n", source[i]);
			fd = open(source[i], O_RDWR);
			if (fd > -1)
			{
				int res = 1;
				while (res != 0)
				{
					res = get_next_line(fd, &line);
					printf("free <%p> |%s|\n", line, line);
					printf("res: %d\n", res);
					free(line);
				}
				close(fd);
			}
			i++;
		}

		
		fd = open(source, O_RDWR);
		int res = 1;
		if (fd > -1)
		{
			printf("FIRST\n");
			while (res != 0)
			{
				res = get_next_line(fd, &line);
				printf("free <%p> |%s|\n", line, line);
				printf("res: %d\n", res);
				printf("--- LINE\n");
				free(line);
				printf("---\n");

			}
			res = 1;
			printf("SECOND\n");
			while (res != 0)
			{
				res = get_next_line(fd, &line);
				printf("free <%p> |%s|\n", line, line);
				printf("res: %d\n", res);
				printf("--- LINE\n");
				free(line);
				printf("---\n");
			}
		}
    #endif
    return (0);
}
*/