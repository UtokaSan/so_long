/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:32:21 by fboulbes          #+#    #+#             */
/*   Updated: 2024/12/26 19:14:53 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"
# include "fcntl.h"

void			game_init(void);
char			**parsing_map(void);
char			**append_buffer(char **buffer, char *data);
void			free_partial_buffer(char **buffer, int size);
unsigned int	calculate_buffer_size(char **buffer);
int				check_exist_exit(char **map);
int				check_map(char **map);

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map_info
{
	int	collectibles;
	int	exit_found;
}	t_map_info;

#endif