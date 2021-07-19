# include "ft_printf.h"

int main(void)
{
    // char *c = "0 1 2 3 4 5 6 7 8 9 m o p % ^ $ * $ \n";
    // int i = 0;
    // while (c[i])
    // {
    //     ft_printf("%c", c[i]);
    //     // printf("%c", c[i]);
    //     i++;
    // }

	int n;

	n = -123456789;
	ft_printf("\n----\nd: %d\n", n);
	printf("p: %d\n", n);
	n = -1;
	ft_printf("\n----\nd: %d\n", n);
	printf("p: %d\n", n);
	n = -10;
	ft_printf("\n----\nd: %d\n", n);
	printf("p: %d\n", n);
	n = 1;
	ft_printf("\n----\nd: %d\n", n);
	printf("p: %d\n", n);
	n = 10;
	ft_printf("\n----\nd: %d\n", n);
	printf("p: %d\n", n);
	n = 506;
	ft_printf("\n----\nd: %d\n", n);
	printf("p: %d\n", n);
	n = 6405;
	ft_printf("\n----\nd: %d\n", n);
	printf("p: %d\n", n);
	n = -994563;
	ft_printf("\n----\nd: %d\n", n);
	printf("p: %d\n", n);
	n = 1597543215;
	ft_printf("\n----\nd: %d\n", n);
	printf("p: %d\n", n);
	n = 0123;
	ft_printf("\n----\nd: %d\n", n);
	printf("p: %d\n", n);
	n = 0x123;
	ft_printf("\n----\nd: %d\n", n);
	printf("p: %d\n", n);

    // char *str = "Hello";
    // char *str2 = "World";
    // char ch = '!';
    // ft_printf("%s%%%s%c", str, str2, ch);
    // printf("\n---\n");
    // printf("%s%%%s%c", str, str2, ch);
    return (0);
}
