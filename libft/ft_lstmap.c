#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cell;
	t_list	*pcell;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	while (lst)
	{
		tmp = lst -> next;
		cell = ft_lstnew(f(lst -> content));
		if (!cell)
			return (NULL);
		pcell -> next = cell;
		pcell = cell;
		free (lst);
		del (lst);
		lst = tmp;
	}
	return (cell);
}
