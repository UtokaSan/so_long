/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:52:07 by fboulbes          #+#    #+#             */
/*   Updated: 2025/01/04 23:07:02 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

int	game_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_printf("Error: mlx_init() failed\n"), 0);
	ft_printf("Game initialized!\n");
	game->mlx_win = mlx_new_window(game->mlx, 1220, 790, "so_long");
	if (!game->mlx_win)
	{
		free_game(game);
		return (ft_printf("Error: mlx_new_window() failed\n"), 0);
	}
	game->map = parsing_map();
	if (!check_map(game->map))
	{
		free_game(game);
		return (0);
	}
	game->player = find_position(game->map, PLAYER);
	load_images(game);
	if (!game->map)
	{
		free_game(game);
		return (ft_printf("Error: parsing_map() failed\n"), 0);
	}
	return (1);
}
