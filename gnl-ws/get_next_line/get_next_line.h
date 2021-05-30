#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
// # include "wraloc.h"
typedef struct s_list
{
	char	*buffer;
	char	*rest;
	int		populated;
	int		read;
	size_t	start;
	size_t	end;
	int		eob;
}	t_list;

int		get_next_line(int fd, char **line);
t_list	*new_status(t_list *s);
void	find_char(t_list *s, char c);
char	*substrjoin(t_list *s, size_t start, size_t end, size_t restlen);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);
#endif