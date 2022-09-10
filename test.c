#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	printf("%s, %i in hexa is %X \n", "now", 13, 13);
	ft_printf("%s, %i in hexa is %X \n", "again", 15, 15);
	return (0);
}