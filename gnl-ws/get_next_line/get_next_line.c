/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:26:35 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/19 14:27:26 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

/*
gcc -Werror -Wextra -Wall -D BUFFER_SIZE=32 get_next_line_utils.c get_next_line.c && ./a.out
*/

static void      find_char(t_status *status, char c)
{
    while (status->tmp[status->start] && status->tmp[status->start] == c) { 
        status->start++;
    }
    status->end = status->start;
    while (status->tmp[status->end])
    {
        if(status->tmp[status->end] == c)
            return ;
        status->end++;
    }
    status->eob = 1;
    return ;
}

static int     conclude(t_status *status, char *line)
{
    status->tmp = ft_substr(status->tmp, status->start, status->end);
    if(!status->tmp)
        return (0);

    line = ft_strjoin(line, status->tmp);
    if (!line)
        return (0);

    free(status->tmp);
    ft_bzero(status->rest, ft_strlen(status->rest));
    status->start = status->end;

    // printf("\n\nline: %s\n", line);
    
    return (1);
}

/*
static int      clear(t_status *status, int error)
{
    ft_bzero(status->buffer, BUFFER_SIZE);
    free(status->buffer);
    ft_bzero(status->rest, ft_strlen(status->rest));
    free(status->rest);
    free(status);
    if (error)
        return (-1);
    return (0);
}*/

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
            status->tmp = ft_strjoin(status->rest, status->buffer);
            if(!status->tmp)
                return (-1);

            find_char(status, '\n');
            if(!status->eob)
            {
                /* NEW LINE FOUND OR EOF */
                if(!conclude(status, *line))
                    return (-1);
                    
                return (1);
            }
            else
            {
                /* END OF BUFFER REACHED */
                free(status->tmp);

                status->tmp = ft_substr(status->buffer, status->start, BUFFER_SIZE - status->start);
                if(!status->tmp)
                    return (-1);

                status->rest = ft_strjoin(status->rest, status->tmp);
                if(!status->rest)
                    return (-1);

                ft_bzero(status->buffer, BUFFER_SIZE);
                free(status->tmp);
                
                status->populated = 0;
            }
        }
        else
        {
            /* CALL READ */
            status->read = read(fd, status->buffer, BUFFER_SIZE);
            if (status->read < 0)
            {
                return (-1);
            }
            if(status->read == 0)
            {
                status->tmp = ft_strjoin(status->rest, status->buffer);
                if(!status->tmp)
                    return (-1);

                if(!conclude(status, *line))
                    return (-1);
                    
                return (0);
            }
            status->start = 0;
            status->end = 0;
            status->eob = 0;
            status->populated = 1;
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