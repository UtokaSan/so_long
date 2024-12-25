/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:31:11 by fboulbes          #+#    #+#             */
/*   Updated: 2024/11/20 18:36:35 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	print_pointer(va_list args)
{
	void			*ptr;
	unsigned long	address;
	int				len;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	address = (unsigned long)ptr;
	write(1, "0x", 2);
	len = putnbr_hex(address, 'a');
	return (len + 2);
}
