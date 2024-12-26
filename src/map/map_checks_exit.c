/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:54:20 by fboulbes          #+#    #+#             */
/*   Updated: 2024/12/26 16:48:39 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_pos	*insert_pos(char **map, t_pos *pos_empty, int *pos_coordinate)
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

static int	check_exit(char **map, t_pos *pos_empty, int pos_coordinate)
{
	int		i;
	int		j;
	int		x;
	int		y;

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
}

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
