/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:20:34 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/05 13:46:03 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*tmp;
	t_list	*p;

	if (lst != NULL && *del != NULL)
	{
		p = *lst;
		while (p)
		{
			tmp = p-> next;
			del(p-> content);
			free (p);
			p = tmp;
		}
	}
	lst = NULL;
}
