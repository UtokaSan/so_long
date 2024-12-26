/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:16:39 by fboulbes          #+#    #+#             */
/*   Updated: 2024/12/26 11:22:05 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**parsing_map(void)
{
	char	**map;
	int		fd;
	char	*line;
	char	**new_map;

	map = NULL;
	fd = open("assets/map/map.ber", O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		new_map = append_buffer(map, line);
		free(line);
		if (!new_map)
		{
			free_partial_buffer(map, calculate_buffer_size(map));
			close(fd);
			return (NULL);
		}
		map = new_map;
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}
