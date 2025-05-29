/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:09:13 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/29 15:17:02 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	handle_key(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		exit_game(mlx);
	else if (keycode == KEY_W || keycode == ARROW_UP)
	{
		mlx->current_player_texture = &mlx->player_texture_up;
		move_player(mlx, 0, -1);
	}
	else if (keycode == KEY_S || keycode == ARROW_DOWN)
	{
		mlx->current_player_texture = &mlx->player_texture_down;
		move_player(mlx, 0, 1);
	}
	else if (keycode == KEY_A || keycode == ARROW_LEFT)
	{
		mlx->current_player_texture = &mlx->player_texture_left;
		move_player(mlx, -1, 0);
	}
	else if (keycode == KEY_D || keycode == ARROW_RIGHT)
	{
		mlx->current_player_texture = &mlx->player_texture_right;
		move_player(mlx, 1, 0);
	}
	mlx->player_moving = 1;
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
	mlx_hook(mlx->win_ptr, 17, 0, handle_close, mlx);
}
