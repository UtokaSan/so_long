/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:31:01 by fboulbes          #+#    #+#             */
/*   Updated: 2024/11/20 18:53:05 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(void)
{
	static char	specifiers[] = "sdcpiuxX%";
	static int	(*actions[])(va_list) = {
		putstr_print,
		decimal_print,
		putchar_print,
		print_pointer,
		decimal_print,
		print_unsigned_decimal,
		print_hex_lowercase,
		print_hex_uppercase,
		print_percent
	};
	size_t		i;

	i = 0;
	while (i < NUM_FLAGS)
	{
		g_flags[i].value = specifiers[i];
		g_flags[i].action = actions[i];
		i++;
	}
}
