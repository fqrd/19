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

    printf("---\n");

	ft_printf("%c", '0');
	printf("\n");
	printf("%c", '0');
	printf("\n");
	ft_printf(" %c ", '0');
	printf("\n");
	printf(" %c ", '0');
	printf("\n");
	ft_printf(" %c", '0' - 256);
	printf("\n");
	printf(" %c", '0' - 256);
	printf("\n");
	ft_printf("%c ", '0' + 256);
	printf("\n");
	printf("%c ", '0' + 256);
	printf("\n");
	ft_printf(" %c %c %c ", '0', 0, '1');
	printf("\n");
	printf(" %c %c %c ", '0', 0, '1');
	printf("\n");
	ft_printf(" %c %c %c ", ' ', ' ', ' ');
	printf("\n");
	printf(" %c %c %c ", ' ', ' ', ' ');
	printf("\n");
	ft_printf(" %c %c %c ", '1', '2', '3');
	printf("\n");
	printf(" %c %c %c ", '1', '2', '3');
	printf("\n");
	ft_printf(" %c %c %c ", '2', '1', 0);
	printf("\n");
	printf(" %c %c %c ", '2', '1', 0);
	printf("\n");
	ft_printf(" %c %c %c ", 0, '1', '2');
	printf("\n");
	printf(" %c %c %c ", 0, '1', '2');
	printf("\n");

    printf("---\n");




    // char *str = "Hello";
    // char *str2 = "World";
    // char ch = '!';
    // ft_printf("%s%%%s%c", str, str2, ch);
    // printf("\n---\n");
    // printf("%s%%%s%c", str, str2, ch);
    return (0);
}