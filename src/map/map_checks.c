/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:26:12 by fboulbes          #+#    #+#             */
/*   Updated: 2024/12/26 15:54:01 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Check if wall exist in border
 * Return 1 if doesn't exist and 0 if exist
**/
static int	check_map_borders(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 || i == calculate_buffer_size(map) - 1)
			{
				if (map[i][j] != '1')
					return (1);
			}
			if (j == 0 || j == ft_strlen(map[i]) - 1)
			{
				if (map[i][j] != '1')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static	int	check_rectangular_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (i > 0 && j != ft_strlen(map[i - 1]))
			return (1);
		i++;
	}
	return (0);
}

static	int	check_contains_all_elements(char **map)
{
	int	i;
	int	j;
	int	exit;
	int	begin;
	int	item;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == "P")
				begin++;
			else if (map[i][j] == "C")
				item++;
			else if (map[i][j] == "E")
				exit++;
		}
	}
	if (exit == 1 && item > 0 && begin > 0)
		return (1);
	return (0);
}
