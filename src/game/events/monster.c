/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:37:55 by fboulbes          #+#    #+#             */
/*   Updated: 2025/01/30 11:41:07 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* 
int	spawn_monster(t_game *game)
{
	t_pos	monster_pos;

	
	if (monster_pos.x == -1 || monster_pos.y == -1)
	{
		ft_printf("Error: monster not found\n");
		return (FALSE);
	}
	game->map[monster_pos.y][monster_pos.x] = FLOOR;
	monster_pos.x = rand() % (int)ft_strlen(game->map[0]);
	monster_pos.y = rand() % (int)calculate_buffer_size(game->map);
	if (game->map[monster_pos.y][monster_pos.x] == FLOOR)
		game->map[monster_pos.y][monster_pos.x] = MONSTER;
	else
		spawn_monster(game);
	return (TRUE);
} */