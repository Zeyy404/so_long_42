/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:22:20 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/24 02:03:42 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	int			player_count;
	int			exit_count;
	int			collectible_count;
	int			collectible_found;
	t_position	player_pos;
}				t_map;

typedef struct s_ff
{
	char		**grid;
	int			collectibles_found;
	int			exit_reached;
}				t_ff;

typedef struct s_texture
{
	void		*img;
	int			width;
	int			height;
}				t_texture;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		*map;
	int			move_count;
	int			frame_count;
	t_texture	wall_texture;
	t_texture	floor_texture;
	t_texture	player_texture;
	t_texture	exit_texture;
	t_texture	collectible_texture;
}				t_mlx;

# define TILE_SIZE 32
# define MAX_MAP_WIDTH 50
# define MAX_MAP_HEIGHT 50

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define EVENT_CLOSE 17

int				has_ber_extension(const char *filename);
void			get_map(const char *filename, t_map *map);
void			check_map_validity(t_map *map);
int				check_reachability(t_map *map);
void			render_map(t_mlx *mlx);

void			free_map(t_map *map);
void			error_exit(char *message, t_map *map);

void			setup_hooks(t_mlx *mlx);
void			move_player(t_mlx *mlx, int dx, int dy);
int				update(t_mlx *mlx);
void			exit_game(t_mlx *mlx);

#endif