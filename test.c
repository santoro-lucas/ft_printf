/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:53:07 by lusantor          #+#    #+#             */
/*   Updated: 2022/09/14 18:22:37 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	num;

	num = -1;
	printf("(%i)\n", printf("%s: %i adress is %p.", "printf", num, &num));
	printf("(%i)\n", ft_printf("%s: %i adress is %p.", "ft_pri", num, &num));
	return (0);
}
