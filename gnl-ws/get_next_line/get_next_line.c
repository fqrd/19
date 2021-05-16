/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:26:35 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/17 01:01:21 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

/*
gcc -Werror -Wextra -Wall -D BUFFER_SIZE=32 get_next_line_utils.c get_next_line.c && ./a.out
*/

static size_t      find_char(char *str, size_t from, char c)
{
    while (str[from])
    {
        if(str[from] == c)
            return (from);
        from++;
    }
    return (from);
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
    if (!line || fd < 0 || BUFFER_SIZE == 0)
        return (-1);



    if (find_char(status->buffer, status->offset, '\n') < BUFFER_SIZE)
    {
        // still \n in current buffer
    }
    else
    {
        // no \n, need to keep the actual rest alongside new read
        // clear previous status->rest
        // copy status->buffer from offset to end in status->rest
        // clear previous buffer
        // call new read
    }
    return (-1);
}


int main(void)
{
    int fd;
    char *source;
    char *line;

    line = "\0";
    #ifdef BUFFER_SIZE
        source = "t_small.txt";
        fd = open(source, O_RDONLY);
        if (fd > -1)
        {
            get_next_line(fd, &line);
            get_next_line(fd, &line);
        }
    #endif
    return (0);
}