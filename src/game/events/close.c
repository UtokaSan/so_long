/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 03:44:42 by fboulbes          #+#    #+#             */
/*   Updated: 2024/12/29 04:06:05 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_close(int keycode, void *param)
{
	ft_printf("Keycode: %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(param, param);
		exit(0);
	}
	return (0);
}
