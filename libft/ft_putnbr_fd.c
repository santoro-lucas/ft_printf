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

#include "libft.h"

static void	putdigit(int d, int fd)
{
	d = '0' + d;
	write(fd, &d, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	n2;

	n2 = n;
	if (n2 < 0)
	{
		ft_putchar_fd('-', fd);
		n2 = n2 * -1;
	}
	if (n2 < 10)
		putdigit(n2 % 10, fd);
	else
	{
		ft_putnbr_fd(n2 / 10, fd);
		ft_putnbr_fd(n2 % 10, fd);
	}
}
