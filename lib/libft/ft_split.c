/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:46:04 by fboulbes          #+#    #+#             */
/*   Updated: 2024/11/19 15:02:39 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	count;
	int	in_word;
	int	i;

	count = 0;
	in_word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static char	*ft_get_next_word(const char **s, char c)
{
	const char	*start;
	char		*word;
	int			len;
	int			i;

	i = 0;
	while (**s == c)
		(*s)++;
	start = *s;
	while ((*s)[i] != '\0' && (*s)[i] != c)
		i++;
	len = i;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, start, len + 1);
	*s += len;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		word_count;
	int		i;

	if (!s)
		return (NULL);
	word_count = ft_count_words(s, c);
	result = malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		result[i] = ft_get_next_word(&s, c);
		if (!result[i])
		{
			while (i > 0)
				free(result[--i]);
			free(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

/* 
int	main(void)
{
	char	**str;
	int		i;

	i = 0;
	str = ft_split("Salut Tu vas bien-sss", ' ');
	while (str[i] != NULL)
	{
		printf("[%s]\n", str[i]);
		i++;
	}
	free(str);
	return (0);
}
 */