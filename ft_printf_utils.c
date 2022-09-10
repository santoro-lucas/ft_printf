/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:53:16 by lusantor          #+#    #+#             */
/*   Updated: 2022/09/10 18:53:17 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
		size_t	dst_size;
		size_t	src_size;

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

int	ft_putstr(char *str)
{
	return (write(1, str, ft_strlen(str)));
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
