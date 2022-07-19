/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 23:16:14 by lusantor          #+#    #+#             */
/*   Updated: 2022/06/27 19:54:23 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (--n && *(unsigned char *) s1 == *(unsigned char *) s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}
