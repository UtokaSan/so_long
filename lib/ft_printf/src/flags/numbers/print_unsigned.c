/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:36:30 by fboulbes          #+#    #+#             */
/*   Updated: 2024/11/20 18:36:47 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	putnbr_unsigned(unsigned int nbr)
{
	if (nbr >= 10)
	{
		putnbr_unsigned(nbr / 10);
		putnbr_unsigned(nbr % 10);
	}
	else
		ft_putchar_fd(nbr + '0', 1);
}

static int	nbrlen_unsigned(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int	print_unsigned_decimal(va_list args)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	putnbr_unsigned(nbr);
	return (nbrlen_unsigned(nbr));
}
