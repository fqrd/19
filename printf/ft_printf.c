/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 16:59:57 by fcaquard          #+#    #+#             */
/*   Updated: 2021/07/18 19:23:22 by fcaquard         ###   ########.fr       */
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
    
    str = (const char *) va_arg(args, const char *);
    if (str == NULL)
        str = "(null)";
    len = ft_strlen(str);
    if (write(1, str, len) > -1)
        **count += len;
}

// // p
// static int ft_hexadecimal_pointer(int arg, int count)
// {
//     count++;
//     return (arg);
// }

// // d
// static int ft_decimal(int arg, int count)
// {
//     count++;
//     return (arg);
// }

// // i
// static int ft_integer(int arg, int count)
// {
//     count++;
//     return (arg);
// }

// // u
// static int ft_unsigned_decimal(int arg, int count)
// {
//     count++;
//     return (arg);
// }

// // xX
// static int ft_hexadecimal_number(int arg, int count)
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
    // if (format == 'd')
    // {
    //     return;
    //     ft_decimal(va_arg(args, int), *count);
    // }
    // if (format == 'i')
    // {
    //     return;
    //     ft_integer(va_arg(args, int), *count);
    // }
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
