/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:42:11 by fcaquard          #+#    #+#             */
/*   Updated: 2021/07/13 14:47:02 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
// # include <fcntl.h>

typedef struct s_list
{
	char	*buffer;
	char	*rest;
	char	*line;
	int		populated;
	size_t	start;
	size_t	end;
}	t_list;

char	*get_next_line(int fd);
t_list	*new_status(t_list *s);
int		find_char(t_list **s, char c);
char	*substrjoin(t_list **s, size_t start, size_t end, size_t restlen);
void	ft_bzero(void *buff, size_t len);
size_t	ft_strlen(const char *str);

#endif