# include "ft_printf.h"
# include <limits.h>

static void test_c(int fo)
{
	if (!fo)
		return;
	printf("\n--- TEST C ---\n");
	char c;
	c = ' ';
	printf(" |%c|", c);
	ft_printf("c: |%c| >>", c);
	printf("\n");
	c = '&';
	printf(" |%c|", c);
	ft_printf("c: |%c| >>", c);
	printf("\n");
	c = '0';
	printf(" |%c|", c);
	ft_printf("c: |%c| >>", c);
	printf("\n");
	c = 12;
	printf(" |%c|", c);
	ft_printf("c: |%c| >>", c);
	printf("\n");
	c = 44;
	printf(" |%c|", c);
	ft_printf("c: |%c| >>", c);
	printf("\n");
}

static void test_s(int fo)
{
	if (!fo)
		return;
	printf("\n--- TEST S ---\n");
	char *s;
	s = "";
	printf(" |%s|", s);
	ft_printf("s: |%s| >>", s);
	printf("\n");
	s = NULL;
	printf(" |%s|", s);
	ft_printf("s: |%s| >>", s);
	printf("\n");
	s = "Bonjour";
	printf(" |%s|", s);
	ft_printf("s: |%s| >>", s);
	// printf("\n");
	// s = "Lorem ipsum folor sit amet, consectetur adipiscing elit. Integer nec odio. Praesent libero. Sed cursus ante dapibus diam. Sed nisi. Nulla quis sem at nibh elementum imperdiet. Duis sagittis ipsum. Praesent mauris. Fusce nec tellus sed augue semper porta. Mauris massa. Vestibulum lacinia arcu eget nulla. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Curabitur sodales ligula in libero. Sed dignissim lacinia nunc. Curabitur tortor. Pellentesque nibh. Aenean quam. In scelerisque sem at folor. Maecenas mattis. Sed convallis tristique sem. Proin ut ligula vel nunc egestas porttitor. Morbi lectus risus, iaculis vel, suscipit quis, luctus non, massa. Fusce ac turpis quis ligula lacinia aliquet. Mauris ipsum. Nulla metus metus, ullamcorper vel, tincidunt sed, euismod in, nibh. Quisque volutpat condimentum velit. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Nam nec ante. Sed lacinia, urna non tincidunt mattis, tortor neque adipiscing diam, a cursus ipsum ante quis turpis. Nulla facilisi. Ut fringilla. Suspendisse potenti. Nunc feugiat mi a tellus consequat imperdiet. Vestibulum sapien. Proin quam. Etiam ultrices. Suspendisse in justo eu magna luctus suscipit. Sed lectus. Integer euismod lacus luctus magna. Quisque cursus, metus vitae pharetra auctor, sem massa mattis sem, at interdum magna augue eget diam. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Morbi lacinia molestie dui. Praesent blandit folor. Sed non quam. In vel mi sit amet augue congue elementum. Morbi in ipsum sit amet pede facilisis laoreet. fonec lacus nunc, viverra nec.";
	// printf(" |%s|", s);
	// ft_printf("s: |%s| >>", s);
	printf("\n");
	s = "123549816169816521654989";
	printf(" |%s|", s);
	ft_printf("s: |%s| >>", s);
	printf("\n");
}

static void test_d(int fo)
{
	if (!fo)
		return;
	printf("\n--- TEST D ---\n");
	int d;
	d = 0;
	printf(" |%d|", d);
	ft_printf("d: |%d| >>", d);
	printf("\n");
}

static void test_p(int fo)
{
	if (!fo)
		return;
	printf("\n--- TEST P---\n");
	char p;

	p = '0';
	// printf("%p  ", &p);
	ft_printf("%p", &p);
	printf("\n");
}


static void test_u(int fo)
{
	if (!fo)
		return;
	printf("\n--- TEST U---\n");
	int u;
	// int i;
	// long long ll; 

	// ll = LLONG_MAX; // MAX
	// printf("pf: %u\n", ll); 
	// ft_printf("ft: %u", ll);
	// i = UINT_MAX; // MAX
	// printf("pf: %u\n", INT_MAX);
	// ft_printf("ft: %u", 9223372036854775807LL);
	u = INT_MAX;
	printf("pf: %d\n", u);
	ft_printf("ft: %d\n", u);
	// printf("\n");
	// u = 122;
	// printf("pf: %u\n", u);
	// ft_printf("ft: %u", u);
	// printf("\n");
	// u = -44;
	// printf("pf: %u\n", u);
	// ft_printf("ft: %u", u);
	// printf("\n");
	// u = -1;
	// printf("pf: %u\n", u);
	// ft_printf("ft: %u", u);
	// printf("\n");
	// u = -1 * 1000000;
	// printf("pf: %u\n", u);
	// ft_printf("ft: %u", u);
	// printf("\n");

}

int main(void)
{
	test_c(0);
	test_s(0);
	test_d(0);
	test_p(0);
	test_u(0);
}