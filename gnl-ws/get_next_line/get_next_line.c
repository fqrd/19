/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:26:35 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/18 19:00:38 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

/*
gcc -Werror -Wextra -Wall -D BUFFER_SIZE=32 get_next_line_utils.c get_next_line.c && ./a.out
*/

static void      find_char(char *str, t_status *status, char c)
{
    while (str[status->start] && str[status->start] == c) { 
        status->start++;
    }
    status->end = status->start;
    while (str[status->end])
    {
        if(str[status->end] == c)
            return ;
        status->end++;
    }
    return ;
}

static void set_default(t_status *status)
{
    status->start = 0;
    status->end = 0;
    status->tmp = "\0";
}

static void destroy_status(t_status *status)
{
    free(status->rest);
    free(status->buffer);
    free(status->tmp);
    free(status);
}
/*
static void clear(t_status *status)
{
    ft_bzero(status->tmp, ft_strlen(status->tmp));
    ft_bzero(status->line, ft_strlen(status->line));
}
*/

int get_next_line(int fd, char **line)
{
    static t_status *status;
    if (!line || fd < 0 || BUFFER_SIZE == 0)
        return (-1);
    *line = "\0";

    if(!status)
        status = new_status();

    while (1)
    {
        if (status->populated)
        {
            find_char(status->buffer, status, '\n');
            if(status->end < BUFFER_SIZE)
            {
                /* NEW LINE FOUND OR EOF */
                status->tmp = ft_substr(status->buffer, status->start, status->end);
                if(!status->tmp)
                    return (-1);
                if(status->start == 0 && status->rest[0] != '\0')
                {
                    *line = ft_strjoin(*line, status->rest);
                    ft_bzero(status->rest, ft_strlen(status->rest));
                }
                *line = ft_strjoin(*line, status->tmp);
                status->start = status->end;
                // printf("\n\nline: %s\n", *line);

                // clear(status);

                if (status->buffer[status->end] == '\0')
                {
                    // destroy_status(status);
                    return (0);
                }
                return (1);
            }
            else
            {
                /* END OF BUFFER REACHED */
                status->tmp = ft_substr(status->buffer, status->start, BUFFER_SIZE - status->start);
                if(!status->tmp)
                    return (-1);
                status->rest = ft_strjoin(status->rest, status->tmp);
                ft_bzero(status->tmp, ft_strlen(status->tmp));
                ft_bzero(status->buffer, BUFFER_SIZE);
                status->populated = 0;
            }
        }
        else
        {
            /* CALL READ */
            read(fd, status->buffer, BUFFER_SIZE);
            set_default(status);
            status->populated = 1;
        }
    }
    destroy_status(status);
    return (-1);
}


/*
int main(void)
{
    int fd;
    char *source;
    char *line;
    #ifdef BUFFER_SIZE
        // source = "t_small.txt";
        source = "t_big.txt";
        fd = open(source, O_RDONLY);
        if (fd > -1)
        {
            // get_next_line(fd, &line);
            while (get_next_line(fd, &line) != 0) { ;}
            // printf("output: %d\n\n",get_next_line(fd, &line));
            // printf("output: %d\n\n",get_next_line(fd, &line));
        }
    #endif
    return (0);
}*/