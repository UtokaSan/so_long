/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:08:25 by fboulbes          #+#    #+#             */
/*   Updated: 2025/01/31 19:04:35 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	launch_game(char *map)
{
	t_game	game;

	if (!game_init(&game, map))
		return (ft_printf("Error: game_init() failed\n"), 0);
	mlx_key_hook(game.mlx_win, detect_key_move, &game);
	mlx_hook(game.mlx_win, 2, 1L << 0, handle_close, &game);
	mlx_hook(game.mlx_win, 17, 0, handle_close_button, &game);
	draw(game, game.map);
	mlx_loop(game.mlx);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (ft_printf("Error: wrong number of arguments\n"), 1);
	launch_game(av[1]);
	return (0);
}
