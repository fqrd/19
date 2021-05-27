/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:26:35 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/27 12:01:08 by fcaquard         ###   ########.fr       */
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


static void     free_variables(t_status *status)
{
    free(status->rest);
    free(status->cut);
    free(status);
}

int get_next_line(int fd, char **line)
{
    static t_status *status;
    if (!line || fd < 0 || BUFFER_SIZE == 0)
        return (-1);
    *line = "\0";
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
                // printf("\\n found\n");
                status->cut = ft_substr(status->buffer, status->start, status->end - status->start);
                if(!status->cut)
                    return (-1);
                *line = ft_strjoin(status->rest, status->cut);
                if(!line)
                    return (-1);
                status->start = ++status->end;
                free(status->cut);
                ft_bzero(status->rest, ft_strlen(status->rest));
                // printf("\nLINE:\n|%s|\n", *line);
                return (1);
            }
            else
            {
                // printf("eob reached\n");
                status->cut = ft_substr(status->buffer, status->start, BUFFER_SIZE - status->start);
                if(!status->rest)
                    return (-1);
                status->rest = ft_strjoin(status->rest, status->cut);
                if(!status->rest)
                    return (-1);
                free(status->cut);
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
                *line = ft_strjoin(status->rest, status->buffer);
                if(!*line)
                    return (-1);
                // printf("\nEOF:\n|%s|\n\n", *line);
                free_variables(status);
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
        // source = "t_small.txt";
        // source = "t_medium.txt";
        source = "t_big.txt";
        fd = open(source, O_RDONLY);
        if (fd > -1)
        {
            while (get_next_line(fd, &line) != 0) { ;}
        }
    #endif
    return (0);
}
*/