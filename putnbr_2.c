/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:36:09 by lusantor          #+#    #+#             */
/*   Updated: 2022/06/28 19:40:35 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static void	putdigit(int d, char formatter)
{
	char	set[17] = "0123456789";
	char	lowerhex[17] = "abcdef";
	char	upperhex[17] = "ABCDEF";
	
	if (formatter == 'p' || formatter == 'x')
		ft_strlcat(set, lowerhex, 17);
	else if (formatter == 'X')
		ft_strlcat(set, upperhex, 17);
	ft_putchar_fd(*(set + d), fd);
}

static void	parse_nbr(int *base, char formatter)
{
	if (formatter == 'd' || formatter == 'i' || formatter == 'u')
		*base = 10;
	else if (formatter == 'p'|| formatter == 'x' || formatter == 'X')
		*base = 16;
}

void	ft_putnbr(int n, char formatter)
{
	long int	n2;
	int			base;
	
	n2 = n;
	parse_nbr(&base, formatter);
	if (n2 < 0)
	{
		ft_putchar_fd('-', 1);
		n2 = n2 * -1;
	}
	if (n2 >= base)
		ft_putnbr(n2 / base, formatter);
	putdigit(n2 % base, formatter);
}
