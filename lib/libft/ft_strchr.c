/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:03:20 by fboulbes          #+#    #+#             */
/*   Updated: 2024/11/19 15:02:39 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	size_t	i;

	i = 0;
	while (string[i] != (char)searchedChar)
	{
		if (string[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)string + i);
}

/* 
int	main(void)
{
	printf("%s", ft_strchr("Hello World", 'o'));
	return (0);
}
 */
