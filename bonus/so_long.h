/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:22:20 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/30 11:40:48 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>

# define TILE_SIZE 32
# define MAX_MAP_WIDTH 64
# define MAX_MAP_HEIGHT 32

# define MAX_STARS 200
# define MAX_ENEMIES 10

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

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_ff
{
	char		**grid;
	int			collectibles_found;
	int			exit_reached;
}				t_ff;

typedef struct s_enemy
{
	int			x;
	int			y;
	int			dir;
	int			last_move_frame;
}				t_enemy;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	int			player_count;
	int			exit_count;
	int			collectible_count;
	int			collectible_found;
	t_enemy		enemies[MAX_ENEMIES];
	int			num_enemies;
	t_position	player_pos;
}				t_map;

typedef struct s_texture
{
	void		*img;
	int			width;
	int			height;
	int			*pixels;
	int			bpp;
	int			line_len;
	int			endian;
}				t_texture;

typedef struct s_star
{
	int			x;
	int			y;
}				t_star;

typedef struct s_animation
{
	float		alpha;
	int			offset;
}				t_animation;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		*map;
	int			move_count;
	int			frame_count;
	t_texture	enemy_texture;
	t_texture	wall_texture;
	t_texture	player_texture_idle;
	t_texture	player_texture_right;
	t_texture	player_texture_left;
	t_texture	player_texture_up;
	t_texture	player_texture_down;
	t_texture	*current_player_texture;
	int			player_moving;
	t_texture	exit_texture;
	t_texture	collectible_texture;
	t_texture	collectible_glow_texture;
	t_texture	floor_texture;
	t_star		stars[MAX_STARS];
	int			num_stars;
}				t_mlx;

int				has_ber_extension(const char *filename);
void			get_map(const char *filename, t_map *map);
void			check_map_validity(t_map *map);
int				check_reachability(t_map *map);
void			render_map(t_mlx *mlx);
int				init_textures(t_mlx *mlx);
void			init_starfield(t_mlx *mlx);
void			draw_starfield(t_mlx *mlx);
void			draw_enemies(t_mlx *mlx);
void			init_enemy(t_map *map, int i, int j);

void			free_map(t_map *map);
void			free_textures(t_mlx *mlx);
void			error_exit(char *message, t_map *map);
void			putstr_on_screen(t_mlx *mlx);

void			setup_hooks(t_mlx *mlx);
void			move_player(t_mlx *mlx, int dx, int dy);
void			init_player(t_map *map, int i, int j);
bool			is_enemy_at(t_mlx *mlx, int x, int y);
void			update_enemies(t_mlx *mlx);
int				update(t_mlx *mlx);
void			exit_state(t_mlx *mlx);
void			exit_game(t_mlx *mlx);

#endif