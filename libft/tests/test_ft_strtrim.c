#include <stdio.h>
#include "../libft.h"

int	test_ft_strtrim(void)
{
	printf("---------------\n----STRTRIM----\n---------------\n");

	printf("%s\n", ft_strtrim("ox9ox9ox9ox9ox9ox9ox9ox9testox9ox9ox9ox9ox9ox9ox9ox9ox9ox9ox9ox9ox9", "ox9"));
	printf("%s\n", ft_strtrim("azhoonsnapazodnonosnaoaoazndnnodanzudnnazudn", "azhoo"));
	printf("%s\n", ft_strtrim("-à&é!'ç&énk'&péoj'à&éh!dàhipnzdk,ôd)&j&édà", "à"));
	printf("%s\n", ft_strtrim(" 	              		ppe	 ", " 	"));
	printf("%s\n", ft_strtrim("\naasjai ,doz\n", "\n"));
	printf("%s\n", ft_strtrim("\t\npmmmmzmmmz\n", "\t\n"));
	printf("%s\n", ft_strtrim("09486oazjpazijdazdazd094", "094"));
	printf("%s\n", ft_strtrim("popopopopopopo", "po"));
	printf("%s\n", ft_strtrim("pémmémémémémém&,en&é!y e&!éy!&éye )&!éye !)&éye&é!çy ç!é!çé!çé", "é"));
	return (0);
}