/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:23:46 by lusantor          #+#    #+#             */
/*   Updated: 2022/06/27 19:43:09 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	number;
	int	sign;

	number = 0;
	sign = 1;
	while (ft_strchr(" \t\n\v\r\f", *nptr) && *nptr != '\0')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	if (!ft_isdigit(*nptr))
		return (0);
	while (ft_isdigit(*nptr))
	{
		number *= 10;
		number += (*nptr - '0');
		nptr++;
	}
	number *= sign;
	return (number);
}
