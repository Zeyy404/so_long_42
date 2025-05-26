/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 09:59:16 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/26 18:57:55 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_enemy_at(t_mlx *mlx, int x, int y)
{
	for (int i = 0; i < mlx->map->num_enemies; i++)
		if (mlx->map->enemies[i].x == x && mlx->map->enemies[i].y == y)
			return (true);
	return (false);
}

void	update_enemies(t_mlx *mlx)
{
	t_enemy	*e;
	int		next_x;
	int		i;

	i = 0;
	while (i < mlx->map->num_enemies)
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
		i++;
	}
	if (is_enemy_at(mlx, mlx->map->player_pos.x, mlx->map->player_pos.y))
		exit_state(mlx);
}

void	draw_enemies(t_mlx *mlx)
{
	int		i;
	float	base_freq;
	float	time;
	float	phase_y;
	float	offset_y;
	t_enemy	*enemy;

	base_freq = 0.002f;
	time = mlx->frame_count * base_freq;
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
