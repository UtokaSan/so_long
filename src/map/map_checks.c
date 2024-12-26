/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:26:12 by fboulbes          #+#    #+#             */
/*   Updated: 2024/12/26 11:26:46 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
