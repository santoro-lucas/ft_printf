/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:53:16 by lusantor          #+#    #+#             */
/*   Updated: 2022/09/13 00:42:35 by lusantor         ###   ########.fr       */
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

int	ft_putnbr(unsigned long int n, unsigned int base, char *set)
{
	int	counter;

	counter = 0;
	if (n >= base)
		counter += ft_putnbr(n / base, base, set);
	counter += ft_putchar(*((n % base) + set));
	return (counter);
}

static int	set_base(char formatter, char *set)
{
	if (ft_strchr("diu", formatter))
	{
		ft_strlcpy(set, DECIMAL_SET, 17);
		return (10);
	}
	else if (formatter == 'X')
		ft_strlcpy(set, UPPERHEX_SET, 17);
	else if (formatter == 'x' || formatter == 'p')
		ft_strlcpy(set, LOWERHEX_SET, 17);
	return (16);
}

int	ft_parse_nbr(long int nbr, char formatter)
{
	char			set[17];
	int				counter;
	unsigned int	base;

	counter = 0;
	base = set_base(formatter, set);
	if (ft_strchr("id", formatter) && nbr < 0)
	{
		counter += ft_putchar('-');
		nbr = nbr * -1;
	}
	if (formatter == 'p')
	{
		counter += ft_putstr("0x");
		counter += ft_putnbr (nbr, base, set);
	}
	else
		counter += ft_putnbr((unsigned int) nbr, base, set);
	return (counter);
}