/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:08:25 by fboulbes          #+#    #+#             */
/*   Updated: 2024/12/26 18:17:04 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	display_map(void)
{
	char	**map;
	int		i;

	map = parsing_map();
	if (!map)
		return (ft_printf("Error\n"), 1);
	ft_printf("Map parsed!\n");
	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}

int	main(void)
{
	char	**map;

	display_map();
	map = parsing_map();
	if (check_map(map))
		printf("Map is valid!\n");
	else
		printf("Map is invalid!\n");
	return (0);
}
