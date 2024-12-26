/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:26:12 by fboulbes          #+#    #+#             */
/*   Updated: 2024/12/26 18:50:22 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Check if wall exist in border
 * Return 1 if doesn't exist and 0 if exist
**/
static int	check_map_borders(char **map)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	printf("Map height: %u\n", calculate_buffer_size(map));
	printf("Map width: %lu\n", ft_strlen(map[0]));
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (i == 0 || i == calculate_buffer_size(map) - 1)
			{
				if (map[i][j] != '1')
				{
					printf("Border error: map[%d][%d] = %c (expected '1')\n", i, j, map[i][j]);
					return (0);
				}
			}
			if ((j == 0 || map[i][j + 1] == '\n' || map[i][j + 1] == '\0') && map[i][j] != '1')
			{
				if (map[i][j] != '1')
				{
					printf("Border error: map[%d][%d] = %c (expected '1')\n", i, j, map[i][j]);
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

static	int	check_rectangular_map(char **map)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (i > 0 && j != ft_strlen(map[i - 1]))
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
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				begin++;
			else if (map[i][j] == 'C')
				item++;
			else if (map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (exit == 1 && item > 0 && begin > 0)
		return (1);
	return (0);
}

int	check_map(char **map)
{
	if (!check_map_borders(map))
	{
		printf("Map border is invalid!\n");
		return (0);
	}
	if (!check_rectangular_map(map))
	{
		printf("Map is not rectangular!\n");
		return (0);
	}
	if (!check_contains_all_elements(map))
	{
		printf("Map doesn't contain all elements!\n");
		return (0);
	}
	if (!check_exist_exit(map))
	{
		printf("Map doesn't contain possible exit!\n");
		return (0);
	}
	return (1);
}
