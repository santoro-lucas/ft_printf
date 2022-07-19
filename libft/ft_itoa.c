/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:59:11 by lusantor          #+#    #+#             */
/*   Updated: 2022/06/27 19:44:38 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*set_array(int n)
{
	unsigned int	figures;
	char			*array;

	figures = 0;
	if (n <= 0)
		figures++;
	while (n)
	{
		n /= 10;
		figures++;
	}
	array = malloc(figures + 1);
	if (!array)
		return (NULL);
	ft_memset(array, '0', figures);
	ft_bzero(array + figures, 1);
	return (array);
}

char	*ft_itoa(int n)
{
	char	*arr;
	size_t	len;

	arr = set_array(n);
	if (!arr)
		return (NULL);
	len = ft_strlen(arr);
	if (n < 0)
		*arr = '-';
	else
		n = -n;
	while (n < 0)
	{
		*(arr + --len) = '0' - (n % 10);
		n /= 10;
	}
	return (arr);
}
