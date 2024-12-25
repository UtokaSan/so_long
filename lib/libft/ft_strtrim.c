/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:10:04 by fboulbes          #+#    #+#             */
/*   Updated: 2024/11/19 15:02:39 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*new_str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	new_str = malloc(end - start + 1);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1 + start, end - start + 1);
	return (new_str);
}
/* 
int	main(void)
{
	printf("%s\n", ft_strtrim("abcd", ""));
	printf("%s\n", ft_strtrim("abcde", ""));
	printf("%s\n", ft_strtrim(" . abcd", " "));
	printf("%s\n", ft_strtrim("ab cd  f    ", " "));
	printf("%s\n", ft_strtrim("xxxzst with x and z and x .  zx  xx z", "z x"));
	printf("%s\n", ft_strtrim("   abxfg  ", "x"));
	printf("%s\n", ft_strtrim(".teste, bla ,.,.", ",."));
	return (0);
}
 */