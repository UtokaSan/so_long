/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:41:35 by fboulbes          #+#    #+#             */
/*   Updated: 2024/11/20 18:50:50 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	search_flags(const char *format, va_list args)
{
	size_t	j;
	char	*flag_pos;
	size_t	count;

	j = 0;
	count = 0;
	while (*format)
	{
		if (*format == '%' && *(++format))
		{
			flag_pos = ft_strchr("sdcpiuxX%", *format);
			if (flag_pos)
			{
				j = flag_pos - "sdcpiuxX%";
				count += g_flags[j].action(args);
			}
			else
				count += write(1, "%", 1) + write(1, format, 1);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	return (count);
}
