/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:53:07 by lusantor          #+#    #+#             */
/*   Updated: 2022/09/10 18:53:08 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	printf("%s, %i in hexa is %X \n", "now", 15, 15);
	ft_printf("%s, %i in hexa is %X \n", "again", 15, 15);

	return (0);
}