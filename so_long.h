/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:22:20 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/20 13:48:45 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
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
	t_position	player_pos;
}				t_map;

typedef struct s_ff
{
	char		**grid;
	int			collectibles_found;
	int			exit_reached;
}				t_ff;

# define TILE_SIZE 32

int				has_ber_extension(const char *filename);
void			get_map(const char *filename, t_map *map);
void			check_map_validity(t_map *map);
int				check_reachability(t_map *map);

void			free_map(t_map *map);
void			error_exit(char *message, t_map *map);

#endif