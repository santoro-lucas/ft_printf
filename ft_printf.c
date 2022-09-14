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
	va_list	args;
	int		counter;

	counter = 0;
	va_start(args, string);
	while (*string)
	{
		if (*string != '%')
			counter += ft_putchar(*string);
		else if (*++string == '%')
			counter += ft_putchar(*string);
		else if (*string == 'c')
			counter += ft_putchar(va_arg(args, int));
		else if (*string == 's')
			counter += ft_putstr(va_arg(args, char *));
		else if (ft_strchr("diuxX", *string))
			counter += ft_parse_nbr(va_arg(args, int), *string);
		else if (*string == 'p')
			counter += ft_parse_nbr(va_arg(args, unsigned long), *string);
		string++;
	}
	va_end(args);
	return (counter);
}
