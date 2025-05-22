/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:30:31 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/22 16:14:26 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_mlx *mlx)
{
	int		x;
	int		y;
	char	tile;

	y = 0;
	while (y < mlx->map->height)
	{
		x = 0;
		while (x < mlx->map->width)
		{
			tile = mlx->map->grid[y][x];
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
				mlx->floor_texture, x * TILE_SIZE, y * TILE_SIZE);
			if (tile == '1')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					mlx->wall_texture, x * TILE_SIZE, y * TILE_SIZE);
			}
            else if (tile == 'P')
            {
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
                    mlx->player_texture, x * TILE_SIZE, y * TILE_SIZE);
            }
            else if (tile == 'C')
            {
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
                    mlx->collectible_texture, x * TILE_SIZE, y * TILE_SIZE);
            }
            else if (tile == 'E')
            {
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
                    mlx->exit_texture, x * TILE_SIZE, y * TILE_SIZE);
            }
			x++;
		}
		y++;
	}
}
