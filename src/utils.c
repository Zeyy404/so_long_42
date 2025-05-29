/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 01:48:17 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/29 23:57:27 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map || !map->grid)
		return ;
	i = 0;
	while (map->grid[i])
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

void	error_exit(char *message, t_map *map)
{
	if (map)
		free_map(map);
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	free_textures(t_mlx *mlx)
{
	if (mlx->wall_texture.img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->wall_texture.img);
	if (mlx->player_texture_idle.img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->player_texture_idle.img);
	if (mlx->player_texture_right.img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->player_texture_right.img);
	if (mlx->player_texture_left.img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->player_texture_left.img);
	if (mlx->player_texture_up.img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->player_texture_up.img);
	if (mlx->player_texture_down.img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->player_texture_down.img);
	if (mlx->collectible_texture.img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->collectible_texture.img);
	if (mlx->exit_texture.img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->exit_texture.img);
	if (mlx->enemy_texture.img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->enemy_texture.img);
}

void	putstr_on_screen(t_mlx *mlx)
{
	char	*move_str;
	char	*display;

	move_str = ft_itoa(mlx->move_count);
	display = ft_strjoin("Moves: ", move_str);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 20, 0xFFFFFF, display);
	free(move_str);
	free(display);
}
