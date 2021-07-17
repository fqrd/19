/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:20:51 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/06 15:01:26 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*next_new;

	if (!lst || !(*f))
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	next_new = new;
	lst = lst->next;
	while (lst)
	{	
		next_new -> next = ft_lstnew((*f)(lst->content));
		if (!next_new->next)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		next_new = next_new->next;
		lst = lst->next;
	}
	return (new);
}
