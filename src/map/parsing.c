/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:16:39 by fboulbes          #+#    #+#             */
/*   Updated: 2025/01/28 14:02:59 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	open_file(int *fd, char *my_map)
{
	char	*buffer;
	size_t	ttl_len;

	ttl_len = ft_strlen("/assets/map/") + ft_strlen(my_map) + 1;
	buffer = malloc(ttl_len);
	if (!buffer)
	{
		ft_printf("Error: malloc() open file failed\n");
		return ;
	}
	buffer[0] = '\0';
	ft_strcat(buffer, "assets/map/");
	ft_strcat(buffer, my_map);
	ft_printf("my_map: %s\n", buffer);
	*fd = open((buffer), O_RDONLY);
	free(buffer);
}

char	**parsing_map(char *my_map)
{
	char	**map;
	int		fd;
	char	*line;
	char	**new_map;

	map = NULL;
	open_file(&fd, my_map);
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
