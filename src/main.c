/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:08:25 by fboulbes          #+#    #+#             */
/*   Updated: 2024/12/31 04:25:13 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_game	game;

	if (!game_init(&game))
		return (ft_printf("Error: game_init() failed\n"), 1);
	mlx_key_hook(game.mlx_win, detect_key_move, &game);
	mlx_hook(game.mlx_win, 2, 1L << 0, handle_close, &game);
	draw(game, game.map);
	mlx_loop(game.mlx);
	return (0);
}
