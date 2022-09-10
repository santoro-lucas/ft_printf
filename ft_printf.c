#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*str++ != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
		while ((*s != (char) c) && (*s != '\0'))
				s++;
		if (*s == (char) c)
				return ((char *) s);
		else
				return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
		size_t  src_size;

		src_size = ft_strlen(src);
		if (size == 0)
				return (src_size);
		while (size-- > 1 && *src != '\0')
				*dst++ = *src++;
		*dst = '\0';
		return (src_size);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
		size_t  dst_size;
		size_t  src_size;

		dst_size = ft_strlen(dst);
		src_size = ft_strlen(src);
		if (size <= dst_size)
				return (size + src_size);
		dst += dst_size;
		size -= dst_size;
		ft_strlcpy(dst, src, size);
		return (dst_size + src_size);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	return (write(1, s, ft_strlen(s)));
}

static void	putdigit(int d, char formatter)
{
	char	set[17] = "0123456789";
	char	lowerhex[17] = "abcdef";
	char	upperhex[17] = "ABCDEF";
	
	if (formatter == 'p' || formatter == 'x')
		ft_strlcat(set, lowerhex, 17);
	else if (formatter == 'X')
		ft_strlcat(set, upperhex, 17);
	ft_putchar(*(set + d));
}

static void	parse_nbr(int *base, char formatter)
{
	if (formatter == 'd' || formatter == 'i' || formatter == 'u')
		*base = 10;
	else if (formatter == 'p'|| formatter == 'x' || formatter == 'X')
		*base = 16;
}

void	ft_putnbr(int n, char formatter)
{
	long int	n2;
	int			base;
	
	n2 = n;
	parse_nbr(&base, formatter);
	if (n2 < 0)
	{
		ft_putchar('-');
		n2 = n2 * -1;
	}
	if (n2 >= base)
		ft_putnbr(n2 / base, formatter);
	putdigit(n2 % base, formatter);
}


int	ft_printf(const char *string, ...)
{
	va_list	argument;
	int		offset;

	offset = 0;
	va_start(argument, string);
	while (*(string + offset))
	{
		if (*(string + offset) == '%')
		{
			offset++;
			if (*(string + offset) == '%')
				ft_putchar('%');
			if (*(string + offset) == 'c')
				ft_putchar(va_arg(argument, int));
			if (*(string + offset) == 's')
				ft_putstr(va_arg(argument, char *));
			if (ft_strchr("pdiuxX", *(string + offset)))
				ft_putnbr(va_arg(argument, int), *(string + offset));
		}
	}
	va_end(argument);
	return (1);
}

int main(void)
{
	printf("here it goes %s", "again");
	ft_printf("here it goes again");
	return (0);
}