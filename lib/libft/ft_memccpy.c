/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:32:16 by fboulbes          #+#    #+#             */
/*   Updated: 2024/11/19 15:02:39 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int ch, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		if (((char *)src)[i] == (char)ch)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
/**
int	main(void)
{
	char	buffer[100];
	char	*result;

	buffer[0] = 0;
	result = ft_memccpy(buffer, "Hello : World", ':', 100);
	printf("Buffer complet : %s\n", buffer);
	if (result != NULL)
	{
		printf("Après les deux points : %s\n", result);
	}
	return (0);
}
*/