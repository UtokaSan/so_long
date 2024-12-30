/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:52:07 by fboulbes          #+#    #+#             */
/*   Updated: 2024/12/30 00:52:26 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_init(void)
{
	t_game		game;
	char		**map;

	map = parsing_map();
	ft_printf("Game initialized!\n");
	game.mlx = mlx_init();
	if (!game.mlx)
		return (ft_printf("Error: mlx_init() failed\n"), 0);
	game.mlx_win = mlx_new_window(game.mlx, 1220, 790, "so_long");
	if (!game.mlx_win)
		return (mlx_destroy_display(game.mlx), free(game.mlx), 1);
	mlx_hook(game.mlx_win, 2, 1L << 0, handle_close, &game);
	draw_wall(game, map);
	draw_collectibles(game, map);
	draw_player(game, map);
	draw_exit(game, map);
	mlx_loop(game.mlx);
	return (0);
}
