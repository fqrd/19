#include <stdio.h>
#include <string.h>
#include "../libft.h"

int test_ft_strnstr()
{
	printf("---------------\n----STRNSTR----\n---------------\n");
	int error = 0;
	int i = 0;
	// char master[67] = "§W[eST7´[EdCF0d:hc§ir} fà-5LDxié;1zL)y8'L0ù!:Sm[Qe-";
	// char *master = "";
	char master[600] = "iMS84rlb5RG4Q7CRr)y8'5mLriWDmoIpMOH6AxtLTYzRvK3KBXwHRuCYVscSia3OLLBMsGqDEfftxK8RA7e2o0Gsb0mFGmw1FH0tRqxcY7kmRHFBZ61XrMLIHP6OPfug7UYCIrmuFVlmGV2OTZs33PKseFlouilqVX6M8uwWQKJ17YNDqpf4tgIK94Zwi2LQ9nrARrq57Vk7pPNLggL0Xt5JdfGxt9u4LZnRlgyQFWlQesHUoZdDDWACFhN6LRZT1Xx6E73etJMU0jrY1h425dYLPE0vLyf3frmHMMDgizf95o4FmVAbzZXNJ7en3XdrjCkXuDT2FXEZG3qBojaQSqJISDSAc5TpRNsu4glwC7FiPja5AX9h0ADcsZhhtAY0Q0A91ov0Majk8onNTPz69Z7UIrMc0UajVAEe2inrZTRp0PCYgpd115WYqdn8l8tEMjPYO6GlTCgXNIMt28ANpA5JwkKnWL7t6J6dGNNQcBaEyWYcQ5kHOVqnNC0h0JZ9JHvtfiG3MFTB8xcMxEM2jP6LFPUkF7bPnNbjSN9Ps8WdnP5iMHSd8bCxO1SNSvu62S3QKMphOgGR8HiKzPgj7efq";


	char string[10][723] = {
		"d:hc§",
		"5LDxié;1z",
		";1zL)y8'L0ù!:Sm[Qe-",
		"F0d:hc§ir}fà-5LD",
		"§1W[eST7´[EdCF",
		"software",
		"02",
		"8'",
		"YzRvK3KBXwHRuCYVscSia3OLLBMsGqDEfftxK8RA7e2o0Gsb0mFGmw1FH0tRqxcY7kmRHFBZ61XrMLIHP6OPfug7UYCIrmuFVlmGV2OTZs33PKseFlouilqVX6M8uwWQKJ17YNDqpf4tgIK94Zwi2LQ9nrARrq57Vk7pPNLggL0Xt5JdfGxt9u4LZnRlgyQFWlQesHUoZdDDWACFhN6LRZT1Xx6E73etJMU0jrY1h425dYLPE0vLyf3frmHMMDgizf95o4FmVAbzZXNJ7en3XdrjCkXuDT2FXEZG3qBojaQSqJISDSAc5TpRNsu4glwC7FiPja5AX9h0ADcsZhhtAY0Q0A91ov0Majk8onNTPz69Z7UIrMc0UajVAEe2inrZTRp0PCYgpd",
		""
	};

	int size =50;

	while (i < 10)
	{
		char *lib = strnstr(master, string[i], size);
		char *own = ft_strnstr(master, string[i], size);

		if(lib != own)
		{
			printf("---\nERROR >> \nlib: %s\nown: %s\n", lib , own);
			error = 1;
		}

		if(lib && own)
		{

			if(strncmp(lib, own, 1000) != 0)
			{
				printf("ERROR:  %s != %s\n", lib , own);
				error = 1;
			}
		}
		i++;
	}
	if(!error)
	{
		printf("OK");
	}
	return (0);
}
