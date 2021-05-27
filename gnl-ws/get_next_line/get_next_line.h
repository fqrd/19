#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <printf.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
// # include "wraloc.h"

typedef struct s_status
{
    char            buffer[BUFFER_SIZE];
    char            *line;
    char			*cut;
    char			*rest;
    int             read;

    int             eob;
    size_t          start;
    size_t          end;
    int             populated;
}                   t_status;

    t_status	*new_status(void);
    int get_next_line(int fd, char **line);
    size_t	ft_strlen(const char *str);
    size_t	ft_strlcpy(char *dest, const char *src, size_t size);
    char	*ft_strjoin_empty(char *s1, char *s2, int do_free);
    char	*ft_substr(char const *s, unsigned int start, size_t len);
    void	ft_bzero(void *s, size_t n);

#endif