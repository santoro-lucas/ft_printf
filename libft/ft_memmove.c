/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 23:17:10 by lusantor          #+#    #+#             */
/*   Updated: 2022/06/27 19:54:38 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rv_memcpy(void *dest, const void *src, size_t n)
{
	dest += n - 1;
	src += n - 1;
	while (n-- > 0)
		*((char *) dest--) = *((char *) src--);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
		rv_memcpy(dest, src, n);
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
