/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:26:35 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/28 18:36:54 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
* gcc -Werror -Wextra -Wall -D BUFFER_SIZE=32 get_next_line_utils.c get_next_line.c && ./a.out
*/

static void	find_char(t_status *s, char c)
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

static	int end_of_line(t_status *s, char **line)
{
	s->cut = ft_substr(s->buffer, s->start, s->end - s->start);
	if (!s->cut)
		return (0);
	*line = ft_strjoin_empty(s->rest, s->cut, 1);
	free(s->cut);
	if (!*line)
		return (0);
	s->cut = NULL;
	s->rest = NULL;
	s->start = ++s->end;
	printf("LINE(eol): %p -> |%s|\n", *line,*line);
	return (1);
}

static	int end_of_buffer(t_status *s)
{
	s->cut = ft_substr(s->buffer, s->start, BUFFER_SIZE - s->start);
	if (!s->cut)
		return (0);
	s->rest = ft_strjoin_empty(s->rest, s->cut, 1);
	free(s->cut);
	if (!s->rest)
		return (0);
	s->cut = NULL;
	s->populated = 0;
	return (1);
}

static int	end_of_file(t_status *s, char **line)
{
	if (!s->rest || ft_strlen(s->rest) == 0)
	{
		*line = malloc(sizeof(char) * 1);
		if (!*line)
			return (0);
		*line[0] = '\0';
	}
	else
	{
		*line = ft_strjoin_empty(s->rest, NULL, 1);
		if (!*line)
			return (0);
		s->rest = NULL;
	}
	printf("LINE(eof): %p ->  |%s|\n", *line,*line);
	return (1);
}

static int	freer_the_almighty(t_status *s, int return_value)
{
	printf("\nFREER THE ALMIGHT -> DO YOU EVEN FREE ?!\n");
	if (s)
	{
		printf("\n------\n[FREEING]\n");
		if (s->rest)
		{
			printf("REST\n");
			free(s->rest);
		}
		if (s->cut)
		{
			printf("CUT\n");
			free(s->cut);
		}
		printf("-> BUFFER\n");
		free(s->buffer);
		printf("-> S\n");
		free(s);
		printf("-------\n");
	}
	return (return_value);
}

int	get_next_line(int fd, char **line)
{
	static t_status	*s;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!s)
		s = new_status();
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
					return (0);
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

// /*
int main(void)
{
    int fd;
    char *source;
    char *line;
    #ifdef BUFFER_SIZE
        // source = "./tests/41_no_nl";
        // source = "./tests/42_no_nl";
        // source = "./tests/43_no_nl";
        // source = "./tests/alternate_line_nl_no_nl";
        // source = "./tests/big_line_no_nl";
        // source = "./tests/empty";
        // source = "./tests/multiple_line_with_nl";
        // source = "./tests/nl";
        // source = "./tests/t_empty.txt";
        // source = "./tests/t_small.txt";
        // source = "./tests/41_with_nl";
        // source = "./tests/42_with_nl";
        source = "./tests/43_with_nl";
        // source = "./tests/alternate_line_nl_with_nl";
        // source = "./tests/big_line_with_nl";
        // source = "./tests/multiple_line_no_nl";
        // source = "./tests/multiple_nlx5";
        // source = "./tests/t_big.txt";
        // source = "./tests/t_medium.txt";
        // source = "./tests/t_empty.txt";
        // source = "./tests/t_small.txt";
        // source = "./tests/t_medium.txt";
        // source = "./tests/t_big.txt";
        fd = open(source, O_RDONLY);
        if (fd > -1)
        {
            // while (get_next_line(fd, &line) != 0) { ;}
            int res = 1;
            while (res != 0)
            {
                res = get_next_line(fd, &line);
				printf("free <%p> |%s|\n", line, line);
                free(line);
            }
        }
    #endif
    return (0);
}
// */