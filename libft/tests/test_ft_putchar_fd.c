#include <fcntl.h>
#include "../libft.h"

int putchar_fd(void)
{
	int fd;
	fd = open("./p", O_WRONLY);
	ft_putchar_fd('f', fd);
	return (0);
}