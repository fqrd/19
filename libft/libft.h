#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
int		atoi	(const char *nptr);
int		isalnum	(int c);
int		isalpha	(int c);
int		isascii	(int c);
int		isdigit	(int c);
int		isprint	(int c);
char	*strchr	(const char *s, int c);
size_t	strlcpy	(char *dst, const char *src, size_t size);
size_t	strlcat	(char *dst, const char *src, size_t size);
size_t	strlen	(const char *s);
int		strncmp	(const char *s1, const char *s2, size_t n);
char	*strnstr(const char *big, const char *little, size_t len);
char	*strrchr(const char *s, int c);
int		tolower	(int c);
int		toupper	(int c);
#endif
