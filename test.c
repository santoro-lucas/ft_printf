/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:53:07 by lusantor          #+#    #+#             */
/*   Updated: 2022/09/12 19:58:29 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	number;

	number = -2147483648;
	printf("(%i)\n", printf("%s: %i in hexa is %X.", "printf", number, number));
	printf("(%i)\n", ft_printf("%s: %i in hexa is %X.", "ft_pri", number, number));
	return (0);
}
