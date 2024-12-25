/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:49:44 by fboulbes          #+#    #+#             */
/*   Updated: 2024/11/19 15:02:39 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_copy(char *new_str, char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (s[start] != '\0' && i < len)
	{
		new_str[i] = s[start];
		i++;
		start++;
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_calloc(1, 1));
	if (len > len_s - start)
		len = len_s - start;
	new_str = ft_calloc(len + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	ft_copy(new_str, s, start, len);
	return (new_str);
}
/* 
int	main(void)
{
	printf("%s", ft_substr("hello\n", 0, 2));
	printf("%s", ft_substr("hello\n", 0, 0));
	printf("%s", ft_substr("hello\n", 0, 10));
	printf("%s", ft_substr("hello\n", 1, 10));
	printf("%s", ft_substr("hello\n", 2, 10));
	printf("%s", ft_substr("hello\n", 3, 10));
	printf("%s", ft_substr("hello\n", 4, 10));
	printf("%s", ft_substr("hello\n", 5, 10));
	return (0);
}
 */