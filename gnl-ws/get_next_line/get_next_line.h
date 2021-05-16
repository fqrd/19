#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <printf.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
typedef struct s_status
{
    char			*buffer;
    char			*rest;
    size_t          offset;
}                   t_status;

    t_status	*new_status(void);
    int get_next_line(int fd, char **line);
#endif