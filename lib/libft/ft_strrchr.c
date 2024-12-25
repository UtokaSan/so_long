/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:43:07 by fboulbes          #+#    #+#             */
/*   Updated: 2024/11/19 15:02:39 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	int				occurrence;

	i = 0;
	occurrence = -1;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			occurrence = i;
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	if (occurrence != -1)
		return ((char *)&s[occurrence]);
	return (NULL);
}

/* 
int	main(void)
{
	printf("%s", ft_strrchr("Hello, World!", 'o'));
	printf("%s", strrchr("Hello, World!", 'o'));
	return (0);
}
 */