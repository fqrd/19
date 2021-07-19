/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 16:59:57 by fcaquard          #+#    #+#             */
/*   Updated: 2021/07/19 19:42:29 by fcaquard         ###   ########.fr       */
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

int print_num(int nb, int n)
{
    if (nb < 10 && nb > -10)
    {
        if (nb < 0)
        {
            ft_putchar('-');
            nb *= (-1);
            n++;
        }
        ft_putchar((char) nb + '0');
        n++;
    }
    else
    {
        n = print_num(nb/10, n);
        if (nb < 0)
            ft_putchar((char) (((nb%10) * (-1)) + '0'));
        else
            ft_putchar((char) ((nb%10)+ '0'));
        n++;
    }
    return (n);
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
// static int ft_hexadecimal_pointer(va_list args, int **count)
// {
//     (**count)++;
//     return (arg);
// }

// d&i: OK
static void ft_decimal(va_list args, int **count)
{
    int nbr;

    nbr = (int) va_arg(args, int);
    **count += print_num(nbr, 0);
}

// u
static void ft_unsigned_decimal(va_list args, int **count)
{
    int unbr;

    unbr = (unsigned int) va_arg(args, unsigned int);
    (**count) += print_num(unbr, 0);
}

// // xX
// static int ft_hexadecimal_number(va_list args, int **count, char format)
// {
//     (**count)++;
//     return (arg);
// }

static void function_switch(char format, va_list args, int *count)
{
    if (format == 'c')
        ft_char(args, &count);
    if (format == 's')
        ft_string(args, &count);
    // if (format == 'p')
    //     ft_hexadecimal_pointer(args, &count);
    if (format == 'd' || format == 'i')
        ft_decimal(args, &count);
    if (format == 'u')
        ft_unsigned_decimal(args, &count);
    // if (format == 'x' || format == 'X')
    //     ft_hexadecimal_number(args, &count, format);
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
