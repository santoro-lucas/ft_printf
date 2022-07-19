/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:38:34 by lusantor          #+#    #+#             */
/*   Updated: 2022/06/27 19:49:35 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n > 1
		&& *s1 == *s2
		&& *s1 != '\0'
		&& *s2 != '\0')
	{
		n--;
		s1++;
		s2++;
	}
	return (((unsigned char) *s1) - ((unsigned char) *s2));
}
