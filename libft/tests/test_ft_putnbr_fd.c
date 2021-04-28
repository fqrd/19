#include <fcntl.h>
#include "../libft.h"


int putnbr_fd(void)
{
	int fd;
	int i = 7891011;
	fd = open("./p", O_WRONLY);
	ft_putnbr_fd(i, fd);
	return (0);
}