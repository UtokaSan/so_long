/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:26:12 by fboulbes          #+#    #+#             */
/*   Updated: 2024/12/28 22:57:43 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_map_borders(char **map)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (i == 0 || i == calculate_buffer_size(map) - 1)
			{
				if (map[i][j] != WALL)
					return (0);
			}
			if ((j == 0 || map[i][j + 1] == '\n'
				|| map[i][j + 1] == '\0') && map[i][j] != '1')
			{
				if (map[i][j] != WALL)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_rectangular_map(char **map)
{
	unsigned int	i;
	unsigned int	j;
	size_t			line_length;

	if (!map || !map[0])
		return (0);
	j = 0;
	while (map[0][j] && map[0][j] != '\n')
		j++;
	line_length = j;
	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
			j++;
		if (j != line_length)
			return (0);
		i++;
	}
	return (1);
}

static	int	check_contains_all_elements(char **map)
{
	int	i;
	int	j;
	int	exit;
	int	begin;
	int	item;

	i = 0;
	exit = 0;
	begin = 0;
	item = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j++])
		{
			if (map[i][j] == PLAYER)
				begin++;
			else if (map[i][j] == COLLECTIBLE)
				item++;
			else if (map[i][j] == EXIT)
				exit++;
		}
		i++;
	}
	return (exit == 1 && item > 0 && begin > 0);
}

int	check_map(char **map)
{
	if (!check_map_borders(map))
		return (printf("Map border is invalid!\n"), 0);
	if (!check_rectangular_map(map))
		return (printf("Map is not rectangular!\n"), 0);
	if (!check_contains_all_elements(map))
		return (printf("Map doesn't contain all elements!\n"), 0);
	if (!check_exist_exit(map))
		return (printf("Map doesn't contain possible exit!\n"), 0);
	return (1);
}
