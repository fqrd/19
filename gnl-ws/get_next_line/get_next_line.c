/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:26:35 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/16 15:36:27 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

/*
gcc -Werror -Wextra -Wall -D BUFFER_SIZE=32 get_next_line_utils.c get_next_line.c && ./a.out
*/

static size_t      find_char(char *str, char c)
{
    size_t count;
    
    printf("\n---\nbuffer: %s\n---\n", str);

    count = 0;
    while (*str)
    {
        // printf("%c == %c", *str, c);
        if(*str++ == c)
            return (count);
        count++;
    }
    return (count + 10);
}

int get_next_line(int fd, char **line)
{
    size_t buffer = BUFFER_SIZE;
    size_t offset;
    char *tmp;

    tmp = malloc(sizeof(char) * buffer);
    if (!tmp)
        return (-1);

    if (read(fd, tmp, buffer) > -1)
    {
        if (ft_strlen(tmp) < buffer)
        {
            printf("#1 - EOF\n");
            // ft_strlcat(*line, tmp, ft_strlen(*line) + ft_strlen(tmp));
            // free(tmp);
            // printf("buffer: %s\n", *line);
            return (0);
        }
        offset = find_char(tmp, '\n');
        if (offset <= buffer)
        {
            printf("#2 - /\N\n");
            printf("strlen line: %zu / %s\n", ft_strlen(*line), *line);
            printf("strlen offset: %zu\n", offset);
            printf("strlen line+offset: %zu\n", ft_strlen(*line) + offset);
            
            ft_strlcat(*line, tmp, offset);
            free(tmp);
            printf("offset: %s\n", *line);
            return (1);
        }
        else
        {
            printf("#3 - Continue\n");
            // ft_strlcat(*line, tmp, ft_strlen(*line) + buffer);
            // free(tmp);
            // printf("recc: %s\n", *line);
            get_next_line(fd, line);
        }
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
            // get_next_line(fd, &line);
            // get_next_line(fd, &line);
            // while (get_next_line(fd, &line) > -1){
            //     printf("while: %s\n", line);
            // }
            get_next_line(fd, &line);
            // if (res == -1)
            //     write(1, "error\n", 6);
            // else if (res == -2)
            //     write(1, "exit\n", 6);
            // else
            //     write(1, "EOF\n", 4);
        }
    #endif
    return (0);
}