#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

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

static void ft_char(const int arg)
{
    write(1, &arg, 1);
}

static void ft_string(const char *arg)
{
    if (arg == NULL)
        arg = "(null)";
    write(1, arg, ft_strlen(arg));
}


static int ft_hexadecimal_pointer(int arg)
{
    return (1);
}


static int ft_decimal(int arg)
{
    return (1);
}


static int ft_integer(int arg)
{
    return (1);
}


static int ft_unsigned_decimal(int arg)
{
    return (1);
}


static int ft_hexadecimal_number(int arg)
{
    return (1);
}


static void function_switch(char format, va_list args)
{
    if (format == 'c')
        ft_char(va_arg(args, const int));
    if (format == 's')
        ft_string(va_arg(args, const char *));
    if (format == 'p')
        ft_hexadecimal_pointer(va_arg(args, int));
    if (format == 'd')
        ft_decimal(va_arg(args, int));
    if (format == 'i')
        ft_integer(va_arg(args, int));
    if (format == 'u')
        ft_unsigned_decimal(va_arg(args, int));
    if (format == 'x' || format == 'X')
        ft_hexadecimal_number(va_arg(args, int));
    if (format == '%')
        write (1, "%", 1);
}


void ft_printf(char *format, ...)
{
    va_list args;
    va_start(args, format);
    while (*format)
    {
        while (*format && *format !='%')
        {
            write (1, &*format++, 1);
        }
        if (*format && *(++format))
        {
            function_switch(*format++, args);
        }
    }
    va_end(args);
}

int main(void)
{
    char *str = "Hello";
    char *str2 = "World";
    char ch = '!';
    ft_printf("%s%%%s%c", str, str2, ch);
    printf("\n---\n");
    printf("%s%%%s%c", str, str2, ch);
    return (0);
}