#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <printf.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
//     struct s_list   *first;
// }                   t_list;

    size_t	ft_strlen(const char *str);
    size_t	ft_strlcpy(char *dest, const char *src, size_t size);
    size_t	ft_strlcat(char *dest, const char *src, size_t size);
#endif