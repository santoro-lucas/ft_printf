/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:39:02 by lusantor          #+#    #+#             */
/*   Updated: 2022/06/28 23:16:46 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*s2;
	size_t	len;

	while (ft_strchr(set, *s1) && *s1 != '\0')
		s1++;
	len = ft_strlen(s1);
	while (ft_strchr(set, *(s1 + len - 1)) && len > 0)
		len--;
	s2 = malloc(len + 1);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, len + 1);
	return (s2);
}
