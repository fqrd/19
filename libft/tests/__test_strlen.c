#include <stdio.h>
#include <string.h>
#include "../libft.h"

int test_ft_strlen()
{
	printf("------------\n----STRLEN----\n------------\n");
	int i = 0;
	char table[19][1000] = {"ASCII stands for American Standard Code for Information Interchange. Computers can only understand numbers, so an ASCII code is the numerical representation of a character such as 'a' or '@' or an action of some sort. ASCII was developed a long time ago and now the non-printing characters are rarely used for their original purpose. Below is the ASCII character table and this includes descriptions of the first 32 non-printing characters. ASCII was actually designed for use with teletypes and so the descriptions are somewhat obscure. If someone says they want your CV however in ASCII format, all this means is they want 'plain' text with no formatting such as tabs, bold or underscoring - the raw format that any computer can understand. This is usually so they can easily import the file into their own applications without issues. Notepad.exe creates ASCII text, or in MS Word you can save a file as 'text only'", "-10", "+30", "--150", "++190", "-2147483647", "+2147483647", "-21474836470", "21474836470", " 4", " 5e7", " 7 9", " - 5", " + 6", "-99999999999999999999999999", "99999999999999999999999999", "999999999999999999", "-999999999999999999"};

	while (table[i] && i < 18)
	{
		int n_strlen = strlen(table[i]);
		int n_ftstrlen = ft_strlen(table[i]);
		(n_strlen == n_ftstrlen) ? printf("OK (%s) -> %d \n", table[i], n_ftstrlen): printf("[ERROR] (%s) >> strlen(%d) != ft_atoi(%d)\n", table[i], n_strlen, n_ftstrlen);
		i++;
	}
	return (0);
}