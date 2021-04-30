#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*el;

	el = lst[0];
	while (lst)
	{
		tmp = el -> next;
		free (el);
		del (el);
		el = tmp;
	}
	lst = NULL;
}
