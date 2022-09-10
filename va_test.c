#include <stdarg.h>
#include <stdio.h>

void    va_test(int count, ...)
{
	va_list	ptr;

	va_start(ptr, );
	while (count--)
	{
		printf("%s\n", va_arg);
	}
	va_end();
}

int main(void)
{
	va_test(5, "oi", "tudo", "bem", "como", "vai");
	return (0);
}