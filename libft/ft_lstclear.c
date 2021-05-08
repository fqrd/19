/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:20:34 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/06 14:54:10 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*tmp;

	if (lst != NULL && *del != NULL)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			del((*lst)->content);
			free (*lst);
			*lst = tmp;
		}
	}
	lst = NULL;
}
