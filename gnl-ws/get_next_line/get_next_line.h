#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <printf.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	char	*buffer;
	char	*cut;
	char	*rest;
	int		populated;
	int		read;
	size_t	start;
	size_t	end;
	int		eob;
}				t_list;

t_list	*new_status(t_list *s);
int		get_next_line(int fd, char **line);
char	*substrjoin(t_list *s, size_t start, size_t end);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strjoin_empty(char *s1, char *s2, int do_free);
#endif
