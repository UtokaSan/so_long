/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:52:07 by fboulbes          #+#    #+#             */
/*   Updated: 2025/01/28 14:11:14 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

// free image

int	game_init(t_game *game, char *my_map)
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
	game->map = parsing_map(my_map);
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
