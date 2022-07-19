/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:57:06 by lusantor          #+#    #+#             */
/*   Updated: 2022/06/26 20:15:58 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	char	*dup;
	int		len;

	len = ft_strlen(s) + 1;
	dup = malloc(len);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, len);
	return (dup);
}
