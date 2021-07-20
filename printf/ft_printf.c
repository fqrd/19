/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 16:59:57 by fcaquard          #+#    #+#             */
/*   Updated: 2021/07/20 21:45:41 by fcaquard         ###   ########.fr       */
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

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr(char *s)
{
	return (write(1, s, ft_strlen(s)));
}

int	print_num(long long nb, int n)
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
		n = print_num(nb / 10, n);
		if (nb < 0)
			ft_putchar((char)(((nb % 10) * (-1)) + '0'));
		else
			ft_putchar((char)((nb % 10) + '0'));
		n++;
	}
	return (n);
}

int	to_hex_long(unsigned long long x, int *base, int n)
{
	if (x < 16)
	{
		ft_putchar(base[x]);
		n++;
	}
	else
	{
		n = to_hex_long(x / 16, base, n);
		ft_putchar(base[x % 16]);
		n++;
	}
	return (n);
}

static void	ft_char(va_list args, size_t **count)
{
	unsigned char	c;

	c = (unsigned char)va_arg(args, int);
	**count += ft_putchar(c);
}

static void	ft_string(va_list args, size_t **count)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	**count += ft_putstr(str);
}

static void	ft_decimal(va_list args, size_t **count)
{
	int	nbr;

	nbr = va_arg(args, int);
	**count += print_num((long long)nbr, 0);
}

static void	ft_unsigned_decimal(va_list args, size_t **count)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	(**count) += print_num((long long)nbr, 0);
}

static void	ft_hexadecimal_number(va_list args, size_t **count, char format)
{
	unsigned int	x;
	int				base_x[16] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 97, 98, 99, 100, 101, 102};
	int				base_X[16] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69, 70};

	x = va_arg(args, unsigned int);
	if (format == 'x')
		**count += to_hex_long((unsigned long long)x, base_x, 0);
	else
		**count += to_hex_long((unsigned long long)x, base_X, 0);
}

static void	ft_hexadecimal_pointer(va_list args, size_t **count)
{
	unsigned long long	p;
	int					base[16] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 97, 98, 99, 100, 101, 102};

	p = (unsigned long long)va_arg(args, void *);
	if (!p)
		**count += ft_putstr("(nil)");
	else
	{
		**count += ft_putstr("0x");
		**count += to_hex_long(p, base, 0);
	}
}

static void	function_switch(char format, va_list args, size_t *count)
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
	if (format == 'p')
		ft_hexadecimal_pointer(args, &count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		while (*format && *format != '%')
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
