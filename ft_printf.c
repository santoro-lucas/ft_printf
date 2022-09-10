#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf_utils.h"

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
		else
			ft_putchar(*(string + offset));
		offset++;
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