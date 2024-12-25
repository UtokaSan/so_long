/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:37:49 by fboulbes          #+#    #+#             */
/*   Updated: 2024/11/20 18:36:10 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	putnbr_hex(unsigned long nb, char format_type)
{
	int		len;
	char	*hex_digits;

	len = 0;
	if (format_type == 'a')
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	if (nb >= 16)
	{
		len += putnbr_hex(nb / 16, format_type);
		len += putnbr_hex(nb % 16, format_type);
	}
	else
	{
		ft_putchar_fd(hex_digits[nb], 1);
		len++;
	}
	return (len);
}

int	print_hex_lowercase(va_list args)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	return (putnbr_hex(nbr, 'a'));
}

int	print_hex_uppercase(va_list args)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	return (putnbr_hex(nbr, 'A'));
}
