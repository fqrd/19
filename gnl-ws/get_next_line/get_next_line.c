/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:26:35 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/27 19:46:56 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
gcc -Werror -Wextra -Wall -D BUFFER_SIZE=32 get_next_line_utils.c get_next_line.c && ./a.out
*/


static void      find_char(t_status *status, char c)
{
    while (status->buffer[status->end])
    {
        // printf("c: %c\n",status->buffer[status->end]);
        if(status->buffer[status->end] == c)
        {
            return ;
        }
        status->end++;
    }
    status->eob = 1;
    return ;
}


static int free_on_error(t_status *status, int return_value)
{
    free(status);
    return (return_value);
}


int get_next_line(int fd, char **line)
{    
    if (fd < 0 || !line || BUFFER_SIZE <= 0)
        return (-1);

    static t_status *status;

    if(!status)
    {
        status = new_status();
    }

    while (1)
    {
        if (status->populated)
        {
            find_char(status, '\n');
            if(!status->eob)
            {
                // finds a line break
                // adds the rest in front of it if any
                // clears the rest
                // printf("\\n found\n");
                status->cut = ft_substr(status->buffer, status->start, status->end - status->start);
                if(!status->cut)
                {
                    free(status->cut);
                    return (free_on_error(status, -1));
                }
                // printf("BUFF: |%s|\n", status->buffer);
                // printf("CUT: |%s|\n", status->cut);
                // printf("REST: |%s|\n", status->rest);
                *line = ft_strjoin_empty(status->rest, status->cut, 1);
                free(status->cut);
                if(!*line)
                {
                    free(*line);
                    return (free_on_error(status, -1));
                }
                status->cut = NULL;
                // printf("LINE: %p\n", *line);
                // printf("REST: |%s|\n", status->rest);
                status->rest = NULL;
                status->start = ++status->end;
                // printf("LINE: |%s|\n", *line);
                return (1);
            }
            else
            {
                // reached the end of the buffer
                // concats the rest to the previous one if any
                // does not clear the rest
                // printf("eob reached\n");
                status->cut = ft_substr(status->buffer, status->start, BUFFER_SIZE - status->start);
                if(!status->cut)
                {
                    free(status->cut);
                    return (free_on_error(status, -1));
                }
                // printf("CUTEOB: |%s|\n", status->cut);
                // printf("REST: |%s|\n",status->rest);
                status->rest = ft_strjoin_empty(status->rest, status->cut, 1);
                free(status->cut);
                if(!status->rest)
                {
                    free(status->rest);
                    return (free_on_error(status, -1));
                }
                status->cut = NULL;
                // printf("RESTEOB: |%s|\n", status->rest);
                status->populated = 0;
            }
        }
        else
        {
            /* CALL READ */
            ft_bzero(status->buffer, BUFFER_SIZE);
            status->read = read(fd, status->buffer, BUFFER_SIZE);
            if (status->read < 0)
            {
                return (-1);
            }
            if(status->read == 0)
            {
                if(ft_strlen(status->rest) == 0)
                {
                    *line = malloc(sizeof(char) * 1);
                    if(!*line)
                    {
                        free(*line);
                        return (free_on_error(status, -1));
                    }
                    if(status->rest)
                        free(status->rest);
                    *line[0] = '\0';
                }
                else
                {
                    // printf("REST STRLCPY: |%s|\n", status->rest);
                    *line = ft_strjoin_empty(status->rest, NULL, 1);
                    if(!line)
                    {
                        free(*line);
                        return (free_on_error(status, -1));
                    }
                }
                // printf("REST STRLCPY: |%s|\n", status->rest);
                // printf("LINE: %p\n", *line);
                // printf("EOF: |%s|\n", *line);
                free(status);
                return (0);
            }
            status->start = 0;
            status->end = 0;
            status->eob = 0;
            status->populated = 1;
            status->read = -1;
        }
    }
   return (-1);
}
/*
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
        // source = "./tests/43_with_nl";
        // source = "./tests/alternate_line_nl_with_nl";
        // source = "./tests/big_line_with_nl";
        // source = "./tests/multiple_line_no_nl";
        // source = "./tests/multiple_nlx5";
        // source = "./tests/t_big.txt";
        // source = "./tests/t_medium.txt";
        // source = "./tests/t_empty.txt";
        // source = "./tests/t_small.txt";
        // source = "./tests/t_medium.txt";
        source = "./tests/t_big.txt";
        fd = open(source, O_RDONLY);
        if (fd > -1)
        {
            // while (get_next_line(fd, &line) != 0) { ;}
            int res = 1;
            while (res != 0)
            {
                res = get_next_line(fd, &line);
                free(line);
            }
        }
    #endif
    return (0);
}
*/