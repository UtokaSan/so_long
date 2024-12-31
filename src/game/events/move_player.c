/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 00:56:27 by fboulbes          #+#    #+#             */
/*   Updated: 2024/12/31 04:44:30 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player(char **map, t_pos new_pos)
{
	t_pos	player_pos;

	player_pos = find_position(map, PLAYER);
	if (player_pos.x == -1 || player_pos.y == -1)
	{
		ft_printf("Player not found!\n");
		return (FALSE);
	}
	if (map[new_pos.y][new_pos.x] == WALL)
	{
		printf("Wall detected!\n");
		return (FALSE);
	}
	map[player_pos.y][player_pos.x] = FLOOR;
	map[new_pos.y][new_pos.x] = PLAYER;
	return (TRUE);
}

int	detect_key_move(int keycode, void *param)
{
	t_game	*game;
	t_pos	new_pos;

	game = (t_game *)param;
	new_pos = game->player;
	if (keycode == KEY_W)
		new_pos.y -= 1;
	else if (keycode == KEY_A)
		new_pos.x -= 1;
	else if (keycode == KEY_S)
		new_pos.y += 1;
	else if (keycode == KEY_D)
		new_pos.x += 1;
	else
		return (0);
	if (move_player(game->map, new_pos))
	{
		game->player = new_pos;
		draw(*game, game->map);
	}
	else
		printf("Player not moved!\n");
	return (0);
}
