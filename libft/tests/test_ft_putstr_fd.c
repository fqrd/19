#include <fcntl.h>
#include "../libft.h"

int putstr_fd(void)
{
	int fd;
	char *s;

	s = "oh my god";
	fd = open("./p", O_WRONLY);
	ft_putstr_fd(s, fd);
	return (0);
}