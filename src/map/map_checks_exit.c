/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:54:20 by fboulbes          #+#    #+#             */
/*   Updated: 2024/12/26 19:19:33 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	explore_map(char **map, int x, int y,
t_map_info *map_info)
{
	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	if (map[x][y] == 'C')
		map_info->collectibles--;
	if (map[x][y] == 'E')
		map_info->exit_found = 1;
	map[x][y] = 'V';
	explore_map(map, x - 1, y, map_info);
	explore_map(map, x + 1, y, map_info);
	explore_map(map, x, y - 1, map_info);
	explore_map(map, x, y + 1, map_info);
}

/* static t_pos	*insert_pos(char **map, t_pos *pos_empty, int *pos_coordinate)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				pos_empty[*pos_coordinate].x = i;
				pos_empty[*pos_coordinate].y = j;
				(*pos_coordinate)++;
			}
			j++;
		}
		i++;
	}
	return (pos_empty);
}
 */
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

/* static int	check_exit(char **map, t_pos *pos_empty, int pos_coordinate)
{
	int					i;
	int					j;
	unsigned int		x;
	unsigned int		y;

	i = 0;
	j = 0;
	while (i < pos_coordinate)
	{
		x = pos_empty[i].x;
		y = pos_empty[i].y;
		if ((x > 0 && map[x - 1][y] == 'E') ||
			(x < calculate_buffer_size(map) - 1 && map[x + 1][y] == 'E') ||
			(y > 0 && map[x][y - 1] == 'E') ||
			(y < ft_strlen(map[x]) - 1 && map[x][y + 1] == 'E'))
			return (1);
		i++;
	}
	return (0);
} */

int	check_exist_exit(char **map)
{
	t_pos	*pos_empty;
	int		len;
	int		pos_coordinate;

	len = calculate_buffer_size(map) * ft_strlen(map[0]);
	pos_coordinate = 0;
	pos_empty = malloc(sizeof(t_pos) * len);
	if (!pos_empty)
		return (0);
	pos_empty = insert_pos(map, pos_empty, &pos_coordinate);
	if (check_exit(map, pos_empty, pos_coordinate))
	{
		free(pos_empty);
		return (1);
	}
	free(pos_empty);
	return (0);
}
