/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:32:21 by fboulbes          #+#    #+#             */
/*   Updated: 2025/01/28 13:40:15 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"
# include "fcntl.h"

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct img_game
{
	void	*img;
	int		width;
	int		height;
}	t_img_game;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	char		**map;
	t_pos		player;
	t_img_game	floor_img;
	t_img_game	collectible_img;
	t_img_game	exit_img;
	t_img_game	player_img;
	t_img_game	wall_img;
}	t_game;

int							game_init(t_game *game, char *my_map);
char						**parsing_map(char *my_map);
char						**append_buffer(char **buffer, char *data);
void						free_partial_buffer(char **buffer, int size);
unsigned int				calculate_buffer_size(char **buffer);
unsigned int				check_exist_exit(char **map);
int							check_map(char **map);
int							handle_close(int keycode, void *param);
int							draw(t_game game, char **map);
t_pos						find_position(char **map, char target);
int							detect_key_move(int keycode, void *param);
int							draw_floor(t_game game, char **map);
int							load_images(t_game *game);
int							handle_close_button(void *param);

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

# define WINDOW_WIDTH 1220
# define WINDOW_HEIGHT 790

#endif