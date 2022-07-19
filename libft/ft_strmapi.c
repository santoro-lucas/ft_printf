/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:38:18 by lusantor          #+#    #+#             */
/*   Updated: 2022/06/29 18:21:34 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapi;
	int		i;

	i = 0;
	mapi = malloc(ft_strlen(s) + 1);
	if (!mapi)
		return (NULL);
	while (*(s + i) != '\0')
	{
		*(mapi + i) = f(i, *(s + i));
		i++;
	}
	*(mapi + i) = 0;
	return (mapi);
}
