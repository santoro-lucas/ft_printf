/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:53:07 by lusantor          #+#    #+#             */
/*   Updated: 2022/09/10 22:25:21 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf("%i\n", printf("%s, %u in hexa is %X \n", "printf", -15, -15));
	printf("%i\n", ft_printf("%s, %u in hexa is %X \n", "ft_pri", -15, -15));
	return (0);
}
