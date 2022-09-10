#include <unistd.h>

char	*ft_strchr(const char *s, int c);
size_t  ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int	ft_putchar(char c);
int	ft_putstr(char *str);
static void	putdigit(int d, char formatter);
static void	parse_nbr(int *base, char formatter);
void	ft_putnbr(int n, char formatter);
