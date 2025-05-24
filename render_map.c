/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:30:31 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/24 01:50:44 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update(t_mlx *mlx)
{
	mlx->frame_count++;
	if (mlx->frame_count > 1000000)
		mlx->frame_count = 0;
	render_map(mlx);
	return (0);
}

int	init_textures(t_mlx *mlx)
{
	mlx->floor_texture.img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"textures/floor.xpm", &mlx->floor_texture.width,
			&mlx->floor_texture.height);
	if (!mlx->floor_texture.img)
		return (0);
	mlx->wall_texture.img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"textures/wall.xpm", &mlx->wall_texture.width,
			&mlx->wall_texture.height);
	if (!mlx->wall_texture.img)
		return (0);
	mlx->player_texture.img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"textures/player.xpm", &mlx->player_texture.width,
			&mlx->player_texture.height);
	if (!mlx->player_texture.img)
		return (0);
	mlx->collectible_texture.img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"textures/collectible.xpm", &mlx->collectible_texture.width,
			&mlx->collectible_texture.height);
	if (!mlx->collectible_texture.img)
		return (0);
	mlx->exit_texture.img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"textures/exit.xpm", &mlx->exit_texture.width,
			&mlx->exit_texture.height);
	if (!mlx->exit_texture.img)
		return (0);
	return (1);
}

void	render_map(t_mlx *mlx)
{
	int		x;
	int		y;
	char	tile;
	int		radians;
	int		offset;

	y = 0;
	while (y < mlx->map->height)
	{
		x = 0;
		while (x < mlx->map->width)
		{
			tile = mlx->map->grid[y][x];
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
				mlx->floor_texture.img, x * TILE_SIZE, y * TILE_SIZE);
			radians = (mlx->frame_count + (x * 7 + y * 3)) * 0.1;
			offset = (int)(sin(radians) * 3);
			if (tile == '1')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					mlx->wall_texture.img, x * TILE_SIZE, y * TILE_SIZE
					+ offset);
			}
			else if (tile == 'P')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					mlx->player_texture.img, x * TILE_SIZE, y * TILE_SIZE
					+ offset);
			}
			else if (tile == 'C')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					mlx->collectible_texture.img, x * TILE_SIZE, y * TILE_SIZE
					+ offset);
			}
			else if (tile == 'E')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					mlx->exit_texture.img, x * TILE_SIZE, y * TILE_SIZE
					+ offset);
			}
			x++;
		}
		y++;
	}
}
