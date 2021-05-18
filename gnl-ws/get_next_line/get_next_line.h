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
    char			*tmp;
    char			*rest;
    size_t          offset;
    size_t          lineend;
    int             read;
}                   t_status;

    t_status	*new_status(void);
    int get_next_line(int fd, char **line);
    size_t	ft_strlen(const char *str);
    size_t	ft_strlcpy(char *dest, const char *src, size_t size);
    char	*ft_strjoin(char const *s1, char const *s2);
    char	*ft_substr(char const *s, unsigned int start, size_t len);
    void	ft_bzero(void *s, size_t n);

#endif