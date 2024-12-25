/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:29:16 by fboulbes          #+#    #+#             */
/*   Updated: 2024/11/20 18:31:15 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	putchar_print(va_list args)
{
	char	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}
