/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:26:35 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/18 17:58:04 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

/*
gcc -Werror -Wextra -Wall -D BUFFER_SIZE=32 get_next_line_utils.c get_next_line.c && ./a.out
*/

static void      find_char(char *str, t_status *status, char c)
{
    while (str[status->offset] && str[status->offset] == c) { 
        status->offset++;
    }
    status->lineend = status->offset;
    while (str[status->lineend])
    {
        if(str[status->lineend] == c)
            return ;
        status->lineend++;
    }
    return ;
}

int get_next_line(int fd, char **line)
{
    static t_status *status;
    // *line = dernière ligne trouvée

    /*
    Static = status du reste (entre dernier \n trouvé et fin du buffer).
    Si le buffer est grand et inclus de nombreux \n,
    on va d'abord s'occuper de ceux ci avant de read à nouveau.
    Une fois que le buffer actuel est libre de \n, 
    on refait des read avec la même stratégie jusqu'à EOF.
    */

   /* protect the function from bad inputs */
    if (!line || fd < 0 || BUFFER_SIZE == 0)
        return (-1);
    *line = "\0";

    /* if first call, initializes static variable */
    if(!status)
        status = new_status();

    while (1)
    {
        /* if static variable is initialized and there's a new line remaining in its buffer */
        if (status->read)
        {
            find_char(status->buffer, status, '\n');
            if(status->lineend < BUFFER_SIZE)
            {
                /* NEW LINE FOUND OR EOF */
                status->tmp = ft_substr(status->buffer, status->offset, status->lineend);
                if(!status->tmp)
                    return (-1);
                if(status->offset == 0 && status->rest != NULL)
                {
                    *line = ft_strjoin(*line, status->rest);
                    ft_bzero(status->rest, ft_strlen(status->rest));
                }
                *line = ft_strjoin(*line, status->tmp);
                ft_bzero(status->tmp, ft_strlen(status->tmp));
                status->offset = status->lineend;
                
                printf("\n\nline: %s\n", *line);

                free(status->buffer);
                if (status->buffer[status->lineend] == '\0')
                    return (0);
                return (1);
            }
            else
            {
                /* END OF BUFFER REACHED */
                status->tmp = ft_substr(status->buffer, status->offset, BUFFER_SIZE - status->offset);
                if(!status->tmp)
                    return (-1);
                status->rest = ft_strjoin(status->rest, status->tmp);
                ft_bzero(status->tmp, ft_strlen(status->tmp));
                ft_bzero(status->buffer, BUFFER_SIZE);
                status->read = 0;
            }
        }
        else
        {
            /* CALL READ */
            read(fd, status->buffer, BUFFER_SIZE);
            status->offset = 0;
            status->tmp = "\0";
            status->lineend = 0;
            status->read = 1;
        }
    }
    free(status->buffer);
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