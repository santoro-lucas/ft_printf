#include "libft/libft.a"
#include <stdio.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	ft_putchar_fd(char c, 1);
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
				ft_putchar(va_arg(argument, char));
			if (*(string + offset) == 's')
				ft_putstr(va_arg(argument, char *));
			if (ft_strchr("pdiuxX", *(string + offset))
				putnbr_2(va_arg(argument, int));
		}
	}
	va_end(argument);
}

int main(void)
{
	printf(tal_coisa);
	ft_printf(tal_coisa);
}