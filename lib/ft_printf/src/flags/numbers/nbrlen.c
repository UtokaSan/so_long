/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:04:49 by fboulbes          #+#    #+#             */
/*   Updated: 2024/11/20 19:05:33 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	nbrlen(int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr == -2147483648)
		return (11);
	if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}
