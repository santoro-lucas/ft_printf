/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:38:51 by lusantor          #+#    #+#             */
/*   Updated: 2022/06/27 19:50:04 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	are_same(const char *big, const char *little)
{
	if (ft_strncmp(big, little, ft_strlen(little)) == 0)
		return (1);
	return (0);
}

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	if (len > ft_strlen(big))
		len = ft_strlen(big);
	while (len-- >= (ft_strlen(little)))
	{
		if (are_same(big, little))
			return ((char *) big);
		big++;
	}
	return (NULL);
}
