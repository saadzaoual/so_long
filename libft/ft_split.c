/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <isel-kha@students.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:57:38 by isel-kha          #+#    #+#             */
/*   Updated: 2025/03/25 23:57:40 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	count_words(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
		{
			in_word = 0;
		}
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static	char	*get_next_word(const char **s, char c)
{
	const char	*start;
	size_t		len;
	char		*word;

	while (**s && **s == c)
		(*s)++;
	start = *s;
	while (**s && **s != c)
		(*s)++;
	len = *s - start;
	if (len == 0)
		return (NULL);
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, start, len);
	word[len] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	char	**result;
	size_t	i;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		result[i] = get_next_word(&s, c);
		if (!result[i])
		{
			while (i--)
				free(result[i]);
			free(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
