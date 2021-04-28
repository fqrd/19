#include <fcntl.h>
#include "../libft.h"


int putendl_fd(void)
{
	int fd;
	fd = open("./p", O_WRONLY);
	ft_putendl_fd("xfg", fd);
	return (0);
}