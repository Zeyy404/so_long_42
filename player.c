/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:42:20 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/26 10:34:24 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_state(t_mlx *mlx)
{
	if (mlx->map->collectible_found == mlx->map->collectible_count)
	{
		printf("All collectibles collected!\n");
		printf("You win in %d moves!\n", mlx->move_count);
		exit_game(mlx);
	}
	else if (is_enemy_at(mlx, mlx->map->player_pos.x, mlx->map->player_pos.y))
	{
		printf("You lose! You've been captured by the enemies!\n");
		exit_game(mlx);
	}
	else
	{
		printf("You lose! Failed to collect all collectibles!\n");
		exit_game(mlx);
	}
}

void	move_player(t_mlx *mlx, int dx, int dy)
{
	int new_x;
	int new_y;
	char next_tile;

	new_x = mlx->map->player_pos.x + dx;
	new_y = mlx->map->player_pos.y + dy;
	next_tile = mlx->map->grid[new_y][new_x];
	if (next_tile == '1')
		return ;
	if (next_tile == 'E')
		exit_state(mlx);
	if (next_tile == 'C')
    {
        mlx->map->collectible_found++;
        mlx->map->grid[new_y][new_x] = '0';
    }
	mlx->map->player_pos.x = new_x;
	mlx->map->player_pos.y = new_y;
	mlx->move_count++;
	printf("Moves: %d\n", mlx->move_count);
	render_map(mlx);
}
