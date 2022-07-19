/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:36:46 by lusantor          #+#    #+#             */
/*   Updated: 2022/07/05 01:10:37 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s != c && (count == 0 || *(s - 1) == c))
			count++;
		s++;
	}
	return (count);
}

static void	free_all(char **word_list)
{
	int	i;

	i = 0;
	while (*(word_list + i))
		free(*word_list + i++);
	free(word_list);
	word_list = NULL;
}

static void	fill(char **word_list, const char *s, \
					size_t counter, char c)
{
	size_t	index;
	size_t	start;
	size_t	end;

	index = 0;
	start = 0;
	while (counter--)
	{
		while (s[start] == c && s[start] != '\0')
			start++;
		end = ft_strchr((s + start), c) - (s + start);
		word_list[index] = ft_substr(s, start, end);
		if (!word_list[index])
			free_all(word_list);
		while (s[start] != c && s[start] != '\0')
			start++;
		index++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**word_list;
	size_t	counter;

	if (!s)
		return (NULL);
	counter = count_words(s, c);
	word_list = ft_calloc(counter + 1, sizeof (char *));
	if (word_list)
		fill(word_list, s, counter, c);
	return (word_list);
}
