#include <stddef.h>
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	while (lst)
	{
		i++;
		lst = lst -> next;
	}
	return (i);
}
