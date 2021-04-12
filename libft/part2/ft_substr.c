/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:30:37 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/12 19:41:52 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *p = (char *) s;
	char *sub;
	unsigned int i = 0;

	if (!len || len > ft_strlen(p))
		return (NULL);

	sub = malloc(sizeof(char *) * (len));
	if(!sub)
		return (NULL);

	while (i < start)
	{
		p++;
		i++;
	}
	i = 0;
	while (i < len && *p)
	{
		sub[i] = *p;
		p++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

int main()
{

	char s[10] = "0123456789";
	printf("%s\n",ft_substr(s, 1, 8));

}