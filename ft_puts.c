/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:53:16 by lusantor          #+#    #+#             */
/*   Updated: 2022/09/12 21:09:05 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define DECIMAL_SET "0123456789"
#define LOWERHEX_SET "0123456789abcdef"
#define UPPERHEX_SET "0123456789ABCDEF"

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

int	ft_putnbr_sig(long int n, char formatter)
{
	int	base;
	int	counter;

	counter = 0;
	base = parse_nbr(formatter);
	if (n < 0)
	{
		counter += ft_putchar('-');
		n = n * -1;
	}
	if (n >= base)
		counter += ft_putnbr_sig(n / base, formatter);
	counter += putdigit(n % base, formatter);
	return (counter);
}

int	ft_putnbr_uns(unsigned int n, char formatter)
{
	unsigned int	base;
	static int		counter;

	counter = 0;
	base = parse_nbr(formatter);
	if (n >= base)
		ft_putnbr_uns(n / base, formatter);
	counter += putdigit(n % base, formatter);
	return (counter);
}
