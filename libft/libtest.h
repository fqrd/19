#ifndef LIBTEST_H

# define LIBTEST_H

# include <stddef.h>



////////////////

///////TESTS

/////////////////



/**

 * 	Numbers

 */

int		test_ft_atoi();



/**

 * 	Memory

 */

void	test_ft_bzero();

void	*test_ft_memccpy();

void	*test_ft_memchr();

int		test_ft_memcmp();

void	*test_ft_memcpy();

void	*test_ft_memmove();

void	*test_ft_memset();



/**

 *	Check Strings 

 */

int		test_ft_strlen();

int		test_ft_strncmp();

int		*test_ft_strnstr();

int		*test_ft_strchr();

int		*test_ft_strrchr();



/**

 *	Modify Strings 

 */

// int	test_ft_strlcpy();

// int	test_ft_strlcat();



/**

 * Check ints

 */

int		test_ft_isalnum();

int		test_ft_isalpha();

int		test_ft_isascii();

int		test_ft_isdigit();

int		test_ft_isprint();



/**

 *	Modify ints 

 */

int		test_ft_tolower();

int		test_ft_toupper();







#endif


