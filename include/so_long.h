/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:32:21 by fboulbes          #+#    #+#             */
/*   Updated: 2024/12/29 19:23:47 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"
# include "fcntl.h"

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
}	t_game;

typedef struct img_game
{
	void	*img;
	int		width;
	int		height;
}	t_img_game;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

int							game_init(void);
char						**parsing_map(void);
char						**append_buffer(char **buffer, char *data);
void						free_partial_buffer(char **buffer, int size);
unsigned int				calculate_buffer_size(char **buffer);
unsigned int				check_exist_exit(char **map);
int							check_map(char **map);
int							handle_close(int keycode, void *param);
int							draw_wall(t_game game, char **map);

# define TRUE 1
# define FALSE 0

# define EXIT 'E'
# define PLAYER 'P'
# define WALL '1'
# define COLLECTIBLE 'C'
# define FLOOR '0'

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

#endif