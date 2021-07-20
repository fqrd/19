/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 16:59:57 by fcaquard          #+#    #+#             */
/*   Updated: 2021/07/20 19:52:25 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t  ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	if (!str)
		return (index);
	while (str[index])
		index++;
	return (index);
}

int ft_putchar(char c)
{
    return (write (1, &c, 1));
}

int ft_putstr(char *s)
{
    return (write(1, s, ft_strlen(s)));
}

int print_num(long long nb, long long n)
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

int to_hex(unsigned int x, int *base, int n)
{
    if (x < 16)
    {
        ft_putchar(base[x]);
        n++;
    }
    else
    {
        n = to_hex(x/16, base, n);
        ft_putchar(base[x%16]);
        n++;
    }
    return (n);
}
// c: OK
static void ft_char(va_list args, int **count)
{
    unsigned char c;

    c = (unsigned char) va_arg(args, int);
    **count += ft_putchar(c);
}

// // s: OK
static void ft_string(va_list args, int **count)
{
    char *str;
    
    str = va_arg(args, char *);
    if (str == NULL)
        str = "(null)";
    **count += ft_putstr(str);
}

// d&i: OK
static void ft_decimal(va_list args, int **count)
{
    int nbr;

    nbr = va_arg(args, int);
    **count += print_num((long long) nbr, 0);
}

// u: OK
static void ft_unsigned_decimal(va_list args, int **count)
{
    unsigned int nbr;
    
    nbr = va_arg(args, unsigned int);
    (**count) += print_num((long long) nbr, 0);
}

// xX: OK
static void ft_hexadecimal_number(va_list args, int **count, char format)
{
    unsigned int x;
    int base_x[16] = {48,49,50,51,52,53,54,55,56,57,97,98,99,100,101,102};
    int base_X[16] = {48,49,50,51,52,53,54,55,56,57,65,66,67,68,69,70};
    
    x = va_arg(args, unsigned int);
    if (format == 'x')
        **count += to_hex(x, base_x, 0);
    else 
        **count += to_hex(x, base_X, 0);
}

// p
// static void ft_hexadecimal_pointer(va_list args, int **count)
// {
//     void *p;

//     p = (char *) va_arg(args, void *);
//     **count += ft_putstr(p);
// }

static void function_switch(char format, va_list args, int *count)
{
    if (format == '%')
        *count += ft_putchar('%');
    if (format == 'c')
        ft_char(args, &count);
    if (format == 's')
        ft_string(args, &count);
    if (format == 'd' || format == 'i')
        ft_decimal(args, &count);
    if (format == 'u')
        ft_unsigned_decimal(args, &count);
    if (format == 'x' || format == 'X')
        ft_hexadecimal_number(args, &count, format);
    // if (format == 'p')
    //     ft_hexadecimal_pointer(args, &count);
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
