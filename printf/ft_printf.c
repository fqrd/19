/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 16:59:57 by fcaquard          #+#    #+#             */
/*   Updated: 2021/07/19 17:26:42 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	if (!str)
		return (index);
	while (str[index])
		index++;
	return (index);
}

void    ft_putchar(char c)
{
    write (1, &c, 1);
}

int print_num(int nb)
{
    if (nb < 10 && nb > -10)
    {
        if (nb < 0)
        {
            ft_putchar('-');
            nb *= (-1);
        }
        ft_putchar((char) nb + '0');
    }
    else
    {
        print_num(nb/10);
        if (nb < 0)
            ft_putchar((char) (((nb%10) * (-1)) + '0'));
        else
            ft_putchar((char) ((nb%10)+ '0'));
    }
    return (0);
}

// c: OK
static void ft_char(va_list args, int **count)
{
    char arg;

    arg = (unsigned char) va_arg(args, int);
    if (write(1, &arg, 1) > -1)
        (**count)++;
}

// // s: OK
static void ft_string(va_list args, int **count)
{
    const char *str;
    int len;
    
    len = 0;
    str = (const char *) va_arg(args, const char *);
    if (str == NULL)
        str = "(null)";
    len = ft_strlen(str);
    if (write(1, str, len) > -1)
        **count += len;
}

// // p
// static int ft_hexadecimal_pointer(va_list arg, int **count)
// {
//     count++;
//     return (arg);
// }

// d&i: OK
static void ft_decimal(va_list args, int **count)
{
    int nbr;
    int len;

    len = 1;
    nbr = (int) va_arg(args, int);
    print_num(nbr);
    while (nbr >= 10 || nbr <= -10)
    {
        nbr /= 10;
        len++;
    }
    if (nbr < 0)
        len++;
    **count += len;
}

// // u
// static int ft_unsigned_decimal(va_list arg, int **count)
// {
//     count++;
//     return (arg);
// }

// // xX
// static int ft_hexadecimal_number(va_list arg, int **count)
// {
//     count++;
//     return (arg);
// }

static void function_switch(char format, va_list args, int *count)
{
    if (format == 'c')
        ft_char(args, &count);
    if (format == 's')
        ft_string(args, &count);
    // if (format == 'p')
    // {
    //     return;
    //     ft_hexadecimal_pointer(va_arg(args, int), *count);
    // }
    if (format == 'd' || format == 'i')
    {
        ft_decimal(args, &count);
    }
    // if (format == 'u')
    // {
    //     return;
    //     ft_unsigned_decimal(va_arg(args, int), *count);
    // }
    // if (format == 'x' || format == 'X')
    // {
    //     return;
    //     ft_hexadecimal_number(va_arg(args, int), *count);
    // }
    if (format == '%') // %: OK
    {
        if (write (1, "%", 1) > -1)
            (*count)++;
    }
}

int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int count;
    
    count = 0;
    while (*format)
    {
        while (*format && *format !='%')
        {
            write (1, &*format++, 1);
            count++;
        }
        if (*format && *(++format))
        {
            function_switch(*format++, args, &count);
        }
    }
    va_end(args);
    return (count);
}
