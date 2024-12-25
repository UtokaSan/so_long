/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:50:27 by fboulbes          #+#    #+#             */
/*   Updated: 2024/11/19 15:02:39 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h> 
// #include <string.h>

#include "libft.h"

char	*ft_strnstr(const char *b, const char *l, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	if (l[j] == '\0')
		return ((char *)b);
	if (len == 0)
		return (NULL);
	while (i < len && b[i])
	{
		start = i;
		j = 0;
		while (b[i] == l[j] && i < len && b[i] != '\0' && l[j] != '\0')
		{
			i++;
			j++;
		}
		if (l[j] == '\0')
			return ((char *)&b[start]);
		i = start + 1;
	}
	return (NULL);
}

/*
int	main(void)
{
	printf("%s", ft_strnstr("aaabcabcd", "abcd", 9));
	return (0);
}
*/