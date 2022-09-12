/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:53:07 by lusantor          #+#    #+#             */
/*   Updated: 2022/09/12 17:52:36 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	number;

	number = -11;
	printf("(%i)\n", printf("%s: %i in hexa is %x.", "printf", number, number));
	printf("(%i)\n", ft_printf("%s: %i in hexa is %x.", "ft_pri", number, number));
	return (0);
}
