/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:11:20 by fboulbes          #+#    #+#             */
/*   Updated: 2024/11/19 15:02:39 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_size(int n)
{
	int	digit;

	digit = 0;
	while (n != 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	int		sign;	
	int		len;
	char	*res;

	if (n == 0)
		return (ft_strdup("0"));
	sign = n < 0;
	len = ft_get_size(n) + sign;
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (sign)
	{
		res[0] = '-';
		len--;
		res[len] = -(n % 10) + '0';
		n = -(n / 10);
	}
	while (n != 0)
	{
		len--;
		res[len] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}

/*
int	main(void)
{
	printf("%s", ft_itoa(0));
	return (0);
}
*/
