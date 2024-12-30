/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 00:49:40 by fboulbes          #+#    #+#             */
/*   Updated: 2024/12/30 00:53:49 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_exit(t_game game, char **map)
{
	t_img_game		img_game;
	unsigned int	y;
	unsigned int	x;

	img_game.width = 32;
	img_game.height = 32;
	img_game.img = mlx_xpm_file_to_image(
			game.mlx,
			"assets/textures/rock_stairs_down.xpm",
			&img_game.width, &img_game.height);
	if (!img_game.img)
		return (mlx_destroy_window(game.mlx, game.mlx_win), 1);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == EXIT)
				mlx_put_image_to_window(game.mlx, game.mlx_win,
					img_game.img, x * 32, y * 32);
			x++;
		}
		y++;
	}
	return (0);
}
