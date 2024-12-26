/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:08:25 by fboulbes          #+#    #+#             */
/*   Updated: 2024/12/26 11:24:30 by fboulbes         ###   ########.fr       */
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
	display_map();
	return (0);
}
