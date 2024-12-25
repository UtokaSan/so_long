/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:01:56 by fboulbes          #+#    #+#             */
/*   Updated: 2024/11/19 15:03:15 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned int	i;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
		((unsigned char *)ptr)[i++] = 0;
	return (ptr);
}

/* 
int	main(void)
{
	int	*tab;

	tab = ft_calloc(5, sizeof(int));
	for (int i = 0; i < 5; i++)
		printf("%d ", tab[i]);
	free(tab);
	return (0);
}
 */