#include <stddef.h>
#include <stdlib.h>
#include "libft.h"


t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cell;
	t_list	*prev;
	t_list	*tmp;

	while (lst)
	{
		tmp = lst -> next;
		cell = ft_lstnew(f(lst -> content));
		if (!cell)
			return (NULL);
		cell -> next = prev;
		prev = cell;
		del (lst -> content);
		free(lst);
		lst = tmp;
	}
	return (cell);
}
