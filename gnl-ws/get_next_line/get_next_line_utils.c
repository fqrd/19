/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:26:41 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/17 01:01:01 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_status	*new_status(void)
{
	t_status	*status;

	status = malloc(sizeof(t_status) * 1);
	if (!status)
		return (NULL);
	status->rest = NULL;
	status->offset = 0;
	status->buffer = malloc (sizeof(char) * BUFFER_SIZE);
	if (!status->buffer)
		return (NULL);
	return (status);
}
