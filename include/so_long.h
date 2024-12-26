/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:32:21 by fboulbes          #+#    #+#             */
/*   Updated: 2024/12/26 15:55:09 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"
# include "fcntl.h"

void	game_init(void);
char	**parsing_map(void);
char	**append_buffer(char **buffer, char *data);
void	free_partial_buffer(char **buffer, int size);
int		calculate_buffer_size(char **buffer);

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

#endif