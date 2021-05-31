/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:03:04 by fcaquard          #+#    #+#             */
/*   Updated: 2021/05/31 14:03:06 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char	*buffer;
	char	*rest;
	int		populated;
	int		read;
	size_t	start;
	size_t	end;
	int		eob;
}	t_list;

int		get_next_line(int fd, char **line);
t_list	*new_status(t_list *s);
void	find_char(t_list *s, char c);
char	*substrjoin(t_list *s, size_t start, size_t end, size_t restlen);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);
#endif