/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:53:16 by lusantor          #+#    #+#             */
/*   Updated: 2022/09/12 17:58:47 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define DECIMAL_SET "0123456789"
#define LOWERHEX_SET "0123456789abcdef"
#define UPPERHEX_SET "0123456789ABCDEF"

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
	size_t	src_size;

	src_size = ft_strlen(src);
	if (size == 0)
		return (src_size);
	while (size-- > 1 && *src != '\0')
			*dst++ = *src++;
	*dst = '\0';
	return (src_size);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	if (!str)
		return (write(1, "(null)", ft_strlen("(null)")));
	return (write(1, str, ft_strlen(str)));
}

static int	putdigit(int d, char formatter)
{
	char	set[17];

	if (ft_strchr("diu", formatter))
		ft_strlcpy(set, DECIMAL_SET, 17);
	if (formatter == 'p' || formatter == 'x')
		ft_strlcpy(set, LOWERHEX_SET, 17);
	else if (formatter == 'X')
		ft_strlcpy(set, UPPERHEX_SET, 17);
	return (ft_putchar(*(set + d)));
}

static int	parse_nbr(char formatter)
{
	if (ft_strchr("pxX", formatter))
		return (16);
	return (10);
}

int	ft_putnbr_base(int n, char formatter)
{
	long int	n2;
	int			base;
	int			counter;

	n2 = n;
	counter = 0;
	base = parse_nbr(formatter);
	if (n2 < 0)
	{
		counter += ft_putchar('-');
		n2 = n2 * -1;
	}
	if (n2 >= base)
		counter += ft_putnbr_base(n2 / base, formatter);
	counter += putdigit(n2 % base, formatter);
	return (counter);
}

int	ft_put_unsigned_base(unsigned int n, char formatter)
{
	unsigned int	base;
	static int		counter;

	counter = 0;
	base = parse_nbr(formatter);
	if (n >= base)
		ft_put_unsigned_base(n / base, formatter);
	counter += putdigit(n % base, formatter);
	return (counter);
}
