/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:52:07 by fboulbes          #+#    #+#             */
/*   Updated: 2024/12/25 17:56:08 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(void)
{
	void	*mlx;
	void	*mlx_win;

	ft_printf("Game initialized!\n");
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	mlx_loop(mlx);
}
