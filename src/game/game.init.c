/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:52:07 by fboulbes          #+#    #+#             */
/*   Updated: 2024/12/29 04:26:35 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_init(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		height;
	int		width;

	ft_printf("Game initialized!\n");
	mlx = mlx_init();
	if (!mlx)
		return (1);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	width = 32;
	height = 32;
	img = mlx_xpm_file_to_image(mlx, "assets/textures/brick_gray0.xpm",
			&width, &height);
	if (!img)
		return (mlx_destroy_window(mlx, mlx_win), 1);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 30 * 32); // 1920 / 32 - 1
	mlx_hook(mlx_win, 2, 1L << 0, handle_close, mlx);
	ft_printf("Image loaded!\n");
	mlx_loop(mlx);
	return (0);
}
