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

int	ft_printf(const char *string, ...)
{
	va_list	arguments;
	int		counter;

	counter = 0;
	va_start(arguments, string);
	while (*string)
	{
		if (*string == '%')
		{
			string++;
			if (*string == '%')
				counter += ft_putchar('%');
			if (*string == 'c')
				counter += ft_putchar(va_arg(arguments, int));
			if (*string == 's')
				counter += ft_putstr(va_arg(arguments, char *));
			if (ft_strchr("dipuxX", *string))
				counter += ft_parse_nbr(va_arg(arguments, int), *string);
		}
		else
			counter += ft_putchar(*string);
		string++;
	}
	va_end(arguments);
	return (counter);
}
