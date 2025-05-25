/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:30:31 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/26 00:51:55 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update(t_mlx *mlx)
{
	mlx->frame_count++;
	if (mlx->frame_count % 2 != 0)
		return (0);
	if (mlx->frame_count > 1000000)
		mlx->frame_count = 0;
	if (!mlx->player_moving)
		mlx->current_player_texture = &mlx->player_texture_idle;
	mlx->player_moving = 0;
	render_map(mlx);
	return (0);
}

int	load_texture(t_mlx *mlx, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(mlx->mlx_ptr, path, &tex->width,
			&tex->height);
	if (!tex->img)
		return (0);
	tex->pixels = (int *)mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_len,
			&tex->endian);
	return (1);
}

int	init_textures(t_mlx *mlx)
{
	int	img_width;
	int	img_height;

	if (!load_texture(mlx, &mlx->wall_texture, "textures/wall.xpm")
		|| !load_texture(mlx, &mlx->player_texture_idle, "textures/player.xpm")
		|| !load_texture(mlx, &mlx->player_texture_move,
			"textures/player1.xpm") || !load_texture(mlx,
			&mlx->collectible_texture, "textures/collectible.xpm")
		|| !load_texture(mlx, &mlx->exit_texture, "textures/exit.xpm"))
		return (0);
	img_width = mlx->map->width * TILE_SIZE;
	img_height = mlx->map->height * TILE_SIZE;
	mlx->floor_texture.img = mlx_new_image(mlx->mlx_ptr, img_width, img_height);
	mlx->floor_texture.pixels = (int *)mlx_get_data_addr(mlx->floor_texture.img,
			&mlx->floor_texture.bpp, &mlx->floor_texture.line_len,
			&mlx->floor_texture.endian);
	mlx->floor_texture.width = img_width;
	mlx->floor_texture.height = img_height;
	return (1);
}

void	render_map(t_mlx *mlx)
{
	int		x;
	int		y;
	char	tile;
	float	base_freq;
	float	time;
	float	phase_y;
	int		offset_y;

	base_freq = 0.002f;
	time = mlx->frame_count * base_freq;
	draw_starfield(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->floor_texture.img,
		0, 0);
	y = 0;
	while (y < mlx->map->height)
	{
		x = 0;
		while (x < mlx->map->width)
		{
			tile = mlx->map->grid[y][x];
			phase_y = y * 0.5f;
			offset_y = roundf(cos(time + phase_y) * 1.7f);
			if (tile == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					mlx->wall_texture.img, x * TILE_SIZE, y * TILE_SIZE
					+ offset_y);
			else if (tile == 'P')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					mlx->current_player_texture->img, x * TILE_SIZE, y * TILE_SIZE
					+ offset_y);
			else if (tile == 'C')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					mlx->collectible_texture.img, x * TILE_SIZE, y * TILE_SIZE
					+ offset_y);
			else if (tile == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					mlx->exit_texture.img, x * TILE_SIZE, y * TILE_SIZE
					+ offset_y);
			x++;
		}
		y++;
	}
}
