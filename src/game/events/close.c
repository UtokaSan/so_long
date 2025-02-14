/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 03:44:42 by fboulbes          #+#    #+#             */
/*   Updated: 2025/01/28 10:40:48 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_close(int keycode, void *param)
{
	t_game	*game;

	if (keycode == KEY_ESC)
	{
		game = (t_game *)param;
		if (game && game->mlx && game->mlx_win)
		{
			mlx_destroy_window(game->mlx, game->mlx_win);
			mlx_destroy_display(game->mlx);
			exit(0);
		}
		else
			ft_printf("Error: mlx_destroy_window() failed\n");
		exit(0);
	}
	return (0);
}

int	handle_close_button(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
	return (0);
}
