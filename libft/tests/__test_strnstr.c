#include <stdio.h>
#include <bsd/string.h>

int		ft_strncmp(char *s1, char *s2, unsigned long n);
char	*ft_strnstr(char *str, char *to_find, unsigned long len);

int main()
{
	printf("---------------\n----STRNSTR----\n---------------\n");
	int i = 0;
	char *master = "§W[eST7´[EdCF0d:hc§ir} fà-5LDxié;1zL)y8'L0!:ùSm[Qe-";
	// char *master = "";
	// char master[600] = "iMS84rlb5RG4Q7CRrIJ9b5mLriWDmoIpMOH6AxtLTYzRvK3KBXwHRuCYVscSia3OLLBMsGqDEfftxK8RA7e2o0Gsb0mFGmw1FH0tRqxcY7kmRHFBZ61XrMLIHP6OPfug7UYCIrmuFVlmGV2OTZs33PKseFlouilqVX6M8uwWQKJ17YNDqpf4tgIK94Zwi2LQ9nrARrq57Vk7pPNLggL0Xt5JdfGxt9u4LZnRlgyQFWlQesHUoZdDDWACFhN6LRZT1Xx6E73etJMU0jrY1h425dYLPE0vLyf3frmHMMDgizf95o4FmVAbzZXNJ7en3XdrjCkXuDT2FXEZG3qBojaQSqJISDSAc5TpRNsu4glwC7FiPja5AX9h0ADcsZhhtAY0Q0A91ov0Majk8onNTPz69Z7UIrMc0UajVAEe2inrZTRp0PCYgpd115WYqdn8l8tEMjPYO6GlTCgXNIMt28ANpA5JwkKnWL7t6J6dGNNQcBaEyWYcQ5kHOVqnNC0h0JZ9JHvtfiG3MFTB8xcMxEM2jP6LFPUkF7bPnNbjSN9Ps8WdnP5iMHSd8bCxO1SNSvu62S3QKMphOgGR8HiKzPgj7efq";


	char string[10][723] = {
		"d:hc§",
		"5LDxié;1z",
		"d:hc§ir} fà-5LDxié;1zL)y8'L0!:ùSm[Qe-",
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
		char *n_strnstr = strnstr(master, string[i], size);
		char *x_strnstr = strnstr(master, string[i], size);

		if(n_strnstr == x_strnstr)
		{
			// printf("SAME VALUE >>\n%s\n%s\n", n_strnstr , x_strnstr);
			printf("---\nSAME VALUE\n");
		}
		else
		{
			printf("---\nDIFFERENT VALUE >> \n%s\n%s\n", n_strnstr , x_strnstr);
		}

		if(n_strnstr && x_strnstr)
		{

			if(ft_strncmp(n_strnstr, x_strnstr, 0) == 0)
			{
				// printf("IDENTICAL OUTPUT\n%s\n%s\n", n_strnstr , x_strnstr);
				printf("IDENTICAL OUTPUT\n");
			}
			else
			{
				printf("DIFFERENTS STRINGS:  %s != %s\n", n_strnstr , x_strnstr);
			}
		}
		else
		{
			printf("NO OUTPUT lib: %s == ft_: %s\n", n_strnstr, x_strnstr);
		}
		i++;
	}
	return (0);
}