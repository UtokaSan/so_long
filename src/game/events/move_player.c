/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 00:56:27 by fboulbes          #+#    #+#             */
/*   Updated: 2025/01/31 19:16:07 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collectibles(char **map)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == COLLECTIBLE)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	change_position(char **map, t_pos new_pos)
{
	t_pos	player_pos;

	player_pos = find_position(map, PLAYER);
	if (player_pos.x == -1 || player_pos.y == -1)
		return (FALSE);
	if (map[new_pos.y][new_pos.x] == WALL)
		return (FALSE);
	if (map[new_pos.y][new_pos.x] == EXIT && count_collectibles(map) != 0)
	{
		ft_printf("You need to collect all the collectibles before!\n");
		return (FALSE);
	}
	else if (map[new_pos.y][new_pos.x] == EXIT && count_collectibles(map) == 0)
	{
		ft_printf("You win!\n");
		exit(0);
	}
	map[player_pos.y][player_pos.x] = FLOOR;
	map[new_pos.y][new_pos.x] = PLAYER;
	return (TRUE);
}

int	move_player(t_pos *new_pos, int *keycode)
{
	if (*keycode == KEY_W)
		new_pos->y -= 1;
	else if (*keycode == KEY_A)
		new_pos->x -= 1;
	else if (*keycode == KEY_S)
		new_pos->y += 1;
	else if (*keycode == KEY_D)
		new_pos->x += 1;
	else
		return (0);
	return (1);
}

void	display_counter(t_game *game, int counter)
{
	char	*str;
	int		ttl_len;

	ttl_len = ft_strlen("Moves: ") + ft_strlen(ft_itoa(counter));
	str = malloc(ttl_len + 1);
	if (!str)
		return ;
	str[0] = '\0';
	ft_strcat(str, "Moves: ");
	ft_strcat(str, ft_itoa(counter));
	mlx_string_put(game->mlx, game->mlx_win, 32, 32, 0xFFFFFF,
		str);
	free(str);
}

int	detect_key_move(int keycode, void *param)
{
	t_game		*game;
	t_pos		new_pos;
	static int	count = 0;

	game = (t_game *)param;
	new_pos = game->player;
	if (move_player(&new_pos, &keycode))
	{
		if (change_position(game->map, new_pos))
		{
			game->player = new_pos;
			count++;
			ft_printf("Player moved! %d\n", count);
			draw(*game, game->map);
		}
		else
			printf("Player not moved!\n");
	}
	display_counter(game, count);
	return (0);
}
