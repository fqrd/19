
#include <string.h>
#include <stdio.h>
#include "../libft.h"

int test_ft_memcpy ()
{
	printf("------------\n----MEMCPY----\n------------\n");
	int error = 0;
	int i = 0;
	int *size = { 10, 20, 50, 200, 2000, -1, 0};
	char ldest[723];
	char odest[723];
	char src[10][723] = {
		"d:hc§",
		"5LDxié;1z",
		";1zL)y8'L0ù!:Sm[Qe-",
		"§1W[eST7´[EdCF",
		"software",
		"YzRvK3KBXwHRuCYVscSia3OLLBMsGqDEfftxK8RA7e2o0Gsb0mFGmw1FH0tRqxcY7kmRHFBZ61XrMLIHP6OPfug7UYCIrmuFVlmGV2OTZs33PKseFlouilqVX6M8uwWQKJ17YNDqpf4tgIK94Zwi2LQ9nrARrq57Vk7pPNLggL0Xt5JdfGxt9u4LZnRlgyQFWlQesHUoZdDDWACFhN6LRZT1Xx6E73etJMU0jrY1h425dYLPE0vLyf3frmHMMDgizf95o4FmVAbzZXNJ7en3XdrjCkXuDT2FXEZG3qBojaQSqJISDSAc5TpRNsu4glwC7FiPja5AX9h0ADcsZhhtAY0Q0A91ov0Majk8onNTPz69Z7UIrMc0UajVAEe2inrZTRp0PCYgpd",
		""
	};
	
	while (src[i])
	{
		memcpy(ldest, src[i], size[i]);
		ft_memcpy(odest, src[i], size[i]);
		if (strcmp(ldest, odest) != 0)
		{
			printf("ERROR: (lib): |%s|	!=	|%s| :(yours)	/ |%s| :(src)\n", ldest, odest, src);
			error = 1;
		}
		i++;
	}

	memcpy(NULL, NULL, 10);
	ft_memcpy(NULL, NULL, 10);
	if (strcmp(ldest, odest) != 0)
	{
		printf("ERROR: (lib): |%s|	!=	|%s| :(yours)	/ |%s| :(src)\n", ldest, odest, NULL);
		error = 1;
	}

	if (!error)
	{
		printf("OK\n");
	}
	
	return (0);
}
