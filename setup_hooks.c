/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:09:13 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/22 14:25:30 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void exit_game(t_mlx *mlx)
{
	if (mlx->img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->wall_texture)
		mlx_destroy_image(mlx->mlx_ptr, mlx->wall_texture);
	if (mlx->floor_texture)
		mlx_destroy_image(mlx->mlx_ptr, mlx->floor_texture);
	if (mlx->player_texture)
		mlx_destroy_image(mlx->mlx_ptr, mlx->player_texture);
	free_map(mlx->map);
	exit(EXIT_SUCCESS);
}

static int	handle_key(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		exit_game(mlx);
	else if (keycode == KEY_W || keycode == ARROW_UP)
		move_player(mlx, 0, -1);
	else if (keycode == KEY_S || keycode == ARROW_DOWN)
		move_player(mlx, 0, 1);
	else if (keycode == KEY_A || keycode == ARROW_LEFT)
		move_player(mlx, -1, 0);
	else if (keycode == KEY_D || keycode == ARROW_RIGHT)
		move_player(mlx, 1, 0);
	return (0);
}

static int	handle_close(t_mlx *mlx)
{
	exit_game(mlx);
	return (0);
}

void	setup_hooks(t_mlx *mlx)
{
    mlx_key_hook(mlx->win_ptr, handle_key, mlx);
    mlx_hook(mlx->win_ptr, 17, 0,  handle_close, mlx);
}
