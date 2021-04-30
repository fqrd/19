#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*el;

	el = *lst;
	while (lst)
	{
		tmp = el -> next;
		del (el -> content);
		free (el);
		el = tmp;
	}
	lst = NULL;
}
