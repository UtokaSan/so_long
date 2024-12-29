/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:10:23 by fboulbes          #+#    #+#             */
/*   Updated: 2024/12/29 19:56:44 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_wall(t_game game, char **map)
{
	t_img_game		img_game;
	unsigned int	y;
	unsigned int	x;

	y = 0;
	x = 0;
	img_game.width = 120;
	img_game.height = 120;
	img_game.img = mlx_xpm_file_to_image(
			game.mlx,
			"assets/textures/brick_gray0.xpm",
			&img_game.width, &img_game.height);
	if (!img_game.img)
		return (mlx_destroy_window(game.mlx, game.mlx_win), 1);
	mlx_put_image_to_window(game.mlx, game.mlx_win, img_game.img, 0, 24 * 32);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == WALL && map[y][x] != PLAYER && map[y][x] != EXIT)
				mlx_put_image_to_window(game.mlx, game.mlx_win, img_game.img, x * 32, y * 32);
			x++;
		}
		y++;
	}
	return (0);
}
