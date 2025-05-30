/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 09:59:16 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/29 09:01:47 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_enemy_at(t_mlx *mlx, int x, int y)
{
	int	i;

	i = 0;
	while (i < mlx->map->num_enemies)
	{
		if (mlx->map->enemies[i].x == x && mlx->map->enemies[i].y == y)
			return (true);
		i++;
	}
	return (false);
}

void	update_enemies(t_mlx *mlx)
{
	t_enemy	*e;
	int		next_x;
	int		i;

	i = -1;
	while (++i < mlx->map->num_enemies)
	{
		e = &mlx->map->enemies[i];
		if (mlx->frame_count - e->last_move_frame >= 60)
		{
			next_x = e->x + e->dir;
			if (next_x >= 0 && next_x < mlx->map->width)
			{
				if (mlx->map->grid[e->y][next_x] != '1')
					e->x = next_x;
				else
					e->dir *= -1;
			}
			else
				e->dir *= -1;
			e->last_move_frame = mlx->frame_count;
		}
	}
	if (is_enemy_at(mlx, mlx->map->player_pos.x, mlx->map->player_pos.y))
		exit_state(mlx);
}

void	init_enemy(t_map *map, int i, int j)
{
	map->enemies[map->num_enemies].x = j;
	map->enemies[map->num_enemies].y = i;
	map->enemies[map->num_enemies].dir = 1;
	map->num_enemies++;
	map->grid[i][j] = '0';
}

void	draw_enemies(t_mlx *mlx)
{
	int		i;
	float	time;
	float	phase_y;
	float	offset_y;
	t_enemy	*enemy;

	time = mlx->frame_count * 0.002f;
	i = 0;
	while (i < mlx->map->num_enemies)
	{
		enemy = &mlx->map->enemies[i];
		phase_y = enemy->y * 0.5f;
		offset_y = roundf(cos(time + phase_y) * 1.7f);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->enemy_texture.img, enemy->x * TILE_SIZE, enemy->y * TILE_SIZE
			+ offset_y);
		i++;
	}
}
