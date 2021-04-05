#include <stdio.h>
#include <bsd/string.h>

int		strncmp(const char *s1, const char *s2, unsigned long n);
char	*ft_strnstr(char *str, char *to_find, unsigned long len);

int main()
{
	printf("---------------\n----STRNSTR----\n---------------\n");
	int i = 0;
	char master[67] = "§W[eST7´[EdCF0d:hc§ir} fà-5LDxié;1zL)y8'L0ù!:Sm[Qe-";
	// char *master = "";
	// char master[600] = "iMS84rlb5RG4Q7CRrIJ9b5mLriWDmoIpMOH6AxtLTYzRvK3KBXwHRuCYVscSia3OLLBMsGqDEfftxK8RA7e2o0Gsb0mFGmw1FH0tRqxcY7kmRHFBZ61XrMLIHP6OPfug7UYCIrmuFVlmGV2OTZs33PKseFlouilqVX6M8uwWQKJ17YNDqpf4tgIK94Zwi2LQ9nrARrq57Vk7pPNLggL0Xt5JdfGxt9u4LZnRlgyQFWlQesHUoZdDDWACFhN6LRZT1Xx6E73etJMU0jrY1h425dYLPE0vLyf3frmHMMDgizf95o4FmVAbzZXNJ7en3XdrjCkXuDT2FXEZG3qBojaQSqJISDSAc5TpRNsu4glwC7FiPja5AX9h0ADcsZhhtAY0Q0A91ov0Majk8onNTPz69Z7UIrMc0UajVAEe2inrZTRp0PCYgpd115WYqdn8l8tEMjPYO6GlTCgXNIMt28ANpA5JwkKnWL7t6J6dGNNQcBaEyWYcQ5kHOVqnNC0h0JZ9JHvtfiG3MFTB8xcMxEM2jP6LFPUkF7bPnNbjSN9Ps8WdnP5iMHSd8bCxO1SNSvu62S3QKMphOgGR8HiKzPgj7efq";


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

		if(lib == own)
		{
			printf("---\nOK >>\nlib: %s\nown: %s\n", lib , own);
			// printf("---\nSAME VALUE\n");
		}
		else
		{
			printf("---\nERROR >> \nlib: %s\nown: %s\n", lib , own);
		}

		if(lib && own)
		{

			if(strncmp(lib, own, 1000) == 0)
			{
				// printf("IDENTICAL OUTPUT\n%s\n%s\n", lib , own);
				printf("OK\n");
			}
			else
			{
				printf("ERROR:  %s != %s\n", lib , own);
			}
		}
		else
		{
			printf("NULL lib: %s == ft_: %s\n", lib, own);
		}
		i++;
	}
	return (0);
}