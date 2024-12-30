/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:54:20 by fboulbes          #+#    #+#             */
/*   Updated: 2024/12/29 23:34:42 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static unsigned int	dfs_explore(char **map, int x, int y,
unsigned int **visited)
{
	if ((x < 0 || y < 0 || x >= (int)calculate_buffer_size(map))
		|| (y >= (int)ft_strlen(map[x]) || visited[x][y] || map[x][y] == WALL))
		return (FALSE);
	if (map[x][y] == EXIT)
		return (TRUE);
	visited[x][y] = TRUE;
	if (dfs_explore(map, x + 1, y, visited)
		|| dfs_explore(map, x - 1, y, visited)
		|| dfs_explore(map, x, y + 1, visited)
		|| dfs_explore(map, x, y - 1, visited))
		return (TRUE);
	return (FALSE);
}

static t_pos	find_position(char **map, char target)
{
	t_pos	pos;
	int		i;
	int		j;

	pos.x = -1;
	pos.y = -1;
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == target)
			{
				pos.x = i;
				pos.y = j;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (pos);
}

static int	check_exit(char **map, unsigned int **visited)
{
	t_pos			pos_player;

	pos_player = find_position(map, PLAYER);
	if (pos_player.x == -1 || pos_player.y == -1)
		return (FALSE);
	if (dfs_explore(map, pos_player.x, pos_player.y, visited))
		return (TRUE);
	return (FALSE);
}

unsigned int	check_exist_exit(char **map)
{
	unsigned int	**visited;
	int				i;
	t_pos			pos_player;

	if (!map || !*map)
		return (FALSE);
	pos_player = find_position(map, PLAYER);
	if (pos_player.x == -1 || pos_player.y == -1)
		return (FALSE);
	visited = malloc(sizeof(unsigned int *) * calculate_buffer_size(map));
	if (!visited)
		return (0);
	i = 0;
	while (i < (int)calculate_buffer_size(map))
	{
		visited[i] = malloc(sizeof(unsigned int) * ft_strlen(map[i]));
		if (!visited[i])
			return (free_partial_buffer((char **)visited, i), 0);
		ft_memset(visited[i], 0, sizeof(unsigned int) * ft_strlen(map[i]));
		i++;
	}
	if (check_exit(map, visited))
		return (free_partial_buffer((char **)visited, i), TRUE);
	return (free_partial_buffer((char **)visited, i), FALSE);
}
