/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:53:00 by lusantor          #+#    #+#             */
/*   Updated: 2022/09/10 18:53:00 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define CALLER 
#define FORMATTER *(string + offset)

int	ft_printf(const char *string, ...)
{
	va_list	arguments;
	int		offset;

	offset = 0;
	va_start(arguments, string);
	while (FORMATTER)
	{
		if (FORMATTER == '%')
		{
			offset++;
			if (FORMATTER == '%')
				ft_putchar('%');
			if (FORMATTER == 'c')
				ft_putchar(va_arg(arguments, int));
			if (FORMATTER == 's')
				ft_putstr(va_arg(arguments, char *));
			if (ft_strchr("pdiuxX", FORMATTER))
				ft_putnbr(va_arg(arguments, int), FORMATTER);
		}
		else
			ft_putchar(FORMATTER);
		offset++;
	}
	va_end(arguments);
	return (1);
}
