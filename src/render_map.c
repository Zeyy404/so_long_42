/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:30:31 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/30 00:08:21 by zsalih           ###   ########.fr       */
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
	if (mlx->frame_count % 10 == 0)
		update_enemies(mlx);
	render_map(mlx);
	return (0);
}

static int	load_texture(t_mlx *mlx, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(mlx->mlx_ptr, path, &tex->width,
			&tex->height);
	if (!tex->img)
		return (0);
	return (1);
}

int	init_textures(t_mlx *mlx)
{
	if (!load_texture(mlx, &mlx->wall_texture, "textures_64/wall.xpm")
		|| !load_texture(mlx, &mlx->player_texture_idle,
			"textures_64/player.xpm") || !load_texture(mlx,
			&mlx->player_texture_right, "textures_64/player1.xpm")
		|| !load_texture(mlx, &mlx->player_texture_left,
			"textures_64/player2.xpm") || !load_texture(mlx,
			&mlx->player_texture_up, "textures_64/player3.xpm")
		|| !load_texture(mlx, &mlx->player_texture_down,
			"textures_64/player4.xpm") || !load_texture(mlx,
			&mlx->collectible_texture, "textures_64/collectible.xpm")
		|| !load_texture(mlx, &mlx->exit_texture, "textures_64/exit.xpm")
		|| !load_texture(mlx, &mlx->enemy_texture, "textures_64/enemy.xpm")
		|| !load_texture(mlx, &mlx->collectible_glow_texture,
			"textures_64/collectible1.xpm"))
		return (0);
	mlx->floor_texture.width = mlx->map->width * TILE_SIZE;
	mlx->floor_texture.height = mlx->map->height * TILE_SIZE;
	mlx->floor_texture.img = mlx_new_image(mlx->mlx_ptr,
			mlx->floor_texture.width, mlx->floor_texture.height);
	mlx->floor_texture.pixels = (int *)mlx_get_data_addr(mlx->floor_texture.img,
			&mlx->floor_texture.bpp, &mlx->floor_texture.line_len,
			&mlx->floor_texture.endian);
	mlx->floor_texture.width = mlx->floor_texture.width;
	mlx->floor_texture.height = mlx->floor_texture.height;
	return (1);
}

static void	assign_texture(t_mlx *mlx, char tile, int x, int y)
{
	t_animation	anime;

	anime.offset = roundf(cos(mlx->frame_count * 0.002f + y * 0.5f) * 1.7f);
	if (tile == '1')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->wall_texture.img, x * TILE_SIZE, y * TILE_SIZE + anime.offset);
	else if (tile == 'P')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->current_player_texture->img, x * TILE_SIZE, y * TILE_SIZE
			+ anime.offset);
	else if (tile == 'C')
	{
		anime.alpha = (sinf(mlx->frame_count * 0.08f) + 1) / 2;
		if (anime.alpha < 0.5f)
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
				mlx->collectible_glow_texture.img, x * TILE_SIZE, y * TILE_SIZE
				+ anime.offset);
		else
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
				mlx->collectible_texture.img, x * TILE_SIZE, y * TILE_SIZE
				+ anime.offset);
	}
	else if (tile == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->exit_texture.img, x * TILE_SIZE, y * TILE_SIZE + anime.offset);
}

void	render_map(t_mlx *mlx)
{
	int		x;
	int		y;
	char	tile;

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
			assign_texture(mlx, tile, x, y);
			x++;
		}
		y++;
	}
	draw_enemies(mlx);
	putstr_on_screen(mlx);
}
