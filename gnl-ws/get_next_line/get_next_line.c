/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:26:35 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/18 14:51:55 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

/*
gcc -Werror -Wextra -Wall -D BUFFER_SIZE=32 get_next_line_utils.c get_next_line.c && ./a.out
*/

static void      find_char(char *str, t_status *status, char c)
{
    while (str[status->offset] == c) { 
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

    /* if static variable is initialized and there's a new line remaining in its buffer */
    if (status->read)
    {
        find_char(status->buffer, status, '\n');
        if(status->lineend < BUFFER_SIZE)
        {
            printf("New line found in remaining buffer\n%s\noffset: %zu\nlineend: %zu\n", status->buffer, status->offset, status->lineend);
            status->content = ft_substr(status->buffer, status->offset, status->lineend);
            if(!status->content)
                return (-1);
            // if offset == 0, starts new buffer, maybe we should prepend the rest if any
            if(status->offset == 0 && status->rest != NULL)
                ft_strjoin(*line, status->rest);
            *line = ft_strjoin(*line, status->content);
            status->offset = status->lineend;
            printf("---\nline: %s\n", *line);
            return (1);
        }
        else
        {
            status->rest = ft_substr(status->buffer, status->offset, BUFFER_SIZE - status->offset);
            if(!status->content)
                return (-1);
            ft_bzero(status->buffer, BUFFER_SIZE);
            status->read = 0;
            printf("offset: %zu\n", status->offset);
            printf("lineend: %zu\n", status->lineend);
            printf("buffer: %s\n", status->buffer);
            printf("EOF reached\n");
        }
    }
    else
    {
        printf("Ready to read once more\n");
        status->rest = ft_substr(status->buffer, status->offset, BUFFER_SIZE);
        // no \n, need to keep the actual rest alongside new read
        // clear previous status->rest
        // copy status->buffer from offset to end in status->rest
        // clear previous buffer
        // call new read
        read(fd, status->buffer, BUFFER_SIZE);
        status->read = 1;
    }
    return (-1);
}


int main(void)
{
    int fd;
    char *source;
    char *line;
    #ifdef BUFFER_SIZE
        source = "t_small.txt";
        fd = open(source, O_RDONLY);
        if (fd > -1)
        {
            // get_next_line(fd, &line);
            printf("#1----\n");
            get_next_line(fd, &line);
            printf("#2----\n");
            get_next_line(fd, &line);
            printf("#3----\n");
            get_next_line(fd, &line);
        }
    #endif
    return (0);
}