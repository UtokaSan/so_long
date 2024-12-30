/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 00:56:27 by fboulbes          #+#    #+#             */
/*   Updated: 2024/12/30 01:01:57 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	detect_key_move(void *param, int keycode)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEY_W)
	{
		// Move player up
	}
	else if (keycode == KEY_A)
	{
		// Move player left
	}
	else if (keycode == KEY_S)
	{
		// Move player down
	}
	else if (keycode == KEY_D)
	{
		// Move player right
	}
	return (0);
}