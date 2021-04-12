/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:35:11 by fcaquard          #+#    #+#             */
/*   Updated: 2021/04/12 00:26:05 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include <stdlib.h>
#include <stdio.h>

static char *ft_nbr_to_char(int value, char *str, int index)
{
  if(value < 10)
  {
    str[--index] = value + '0';
  }
  else{
    ft_nbr_to_char(value/10, str, --index);
    str[index] = (value % 10) + '0';
  }
  return (str);
}

static int count_number(int value)
{
  int count = 1;
  while (value > 9 || value < -9)
  {
    value /= 10;
    count++;
  }
  return (count);
}

char *ft_itoa(int value)
{
  char *str;
  int count = count_number(value);
    if(value < 0)
    {
      if(!(str = malloc(sizeof(char) * (count + 2))))
      {
        return (0);
      }
      if(value == -2147483648)
      {
        return (str = "-2147483648\0");
      }
     else
     {
      str[count + 1] = '\0';
      str[0] = '-';
      value *= (-1);
      count++;
     }
    }
    else
    {
      if(!(str = malloc(sizeof(char) * (count + 1))))
      {
        return (0);
      }
      str[count] = '\0';
    }
  ft_nbr_to_char(value, str, count);
  return (str);
}

int main(void) {
  char *str;
  int nbr = -2147483648;
  str = ft_itoa(nbr);
  printf("%s\n", str);  
	return (0);
}