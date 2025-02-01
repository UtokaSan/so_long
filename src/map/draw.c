/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 00:41:45 by fboulbes          #+#    #+#             */
/*   Updated: 2025/02/01 21:31:58 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_img(t_img_game *img_game, char *path, void *mlx)
{
	img_game->width = 32;
	img_game->height = 32;
	img_game->img = mlx_xpm_file_to_image(
			mlx,
			path,
			&img_game->width, &img_game->height);
	return (0);
}

int	load_images(t_game *game)
{
	if (load_img(&game->floor_img, "assets/textures/floor.xpm", game->mlx))
		return (1);
	if (load_img(&game->collectible_img, "assets/textures/collectible.xpm",
			game->mlx))
		return (1);
	if (load_img(&game->exit_img, "assets/textures/exit.xpm", game->mlx))
		return (1);
	if (load_img(&game->player_img, "assets/textures/player.xpm", game->mlx))
		return (1);
	if (load_img(&game->wall_img, "assets/textures/wall.xpm", game->mlx))
		return (1);
	return (0);
}

void	draw_tile(t_game game, char **map, int x, int y)
{
	if (map[y][x] == FLOOR)
		mlx_put_image_to_window(game.mlx, game.mlx_win,
			game.floor_img.img, x * 32, y * 32);
	if (map[y][x] == WALL)
		mlx_put_image_to_window(game.mlx, game.mlx_win,
			game.wall_img.img, x * 32, y * 32);
	else if (map[y][x] == COLLECTIBLE)
		mlx_put_image_to_window(game.mlx, game.mlx_win,
			game.collectible_img.img, x * 32, y * 32);
	else if (map[y][x] == EXIT)
		mlx_put_image_to_window(game.mlx, game.mlx_win,
			game.exit_img.img, x * 32, y * 32);
	else if (map[y][x] == PLAYER)
		mlx_put_image_to_window(game.mlx, game.mlx_win,
			game.player_img.img, x * 32, y * 32);
}

// Draw different floor with % 2 
int	draw(t_game game, char **map)
{
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			draw_tile(game, map, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
