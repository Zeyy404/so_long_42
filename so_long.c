/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:23:59 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/24 02:07:14 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void exit_game(t_mlx *mlx)
{
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->wall_texture.img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->wall_texture.img);
	if (mlx->floor_texture.img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->floor_texture.img);
	if (mlx->player_texture.img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->player_texture.img);
	if (mlx->collectible_texture.img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->collectible_texture.img);
	if (mlx->exit_texture.img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->exit_texture.img);
	free_map(mlx->map);
	exit(EXIT_SUCCESS);
}

void	start_game(t_map *map)
{
	t_mlx	mlx;

	ft_memset(&mlx, 0, sizeof(t_mlx));
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		exit(1);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, map->width * TILE_SIZE, map->height * TILE_SIZE, "so_long");
	if (!mlx.win_ptr)
		exit(1);
	mlx.map = map;
	setup_hooks(&mlx);
	mlx_loop_hook(mlx.mlx_ptr, update, &mlx);
	mlx_loop(mlx.mlx_ptr);
}

int	main(int ac, char **av)
{
	t_map map;

	if (ac == 2)
	{
		if (!has_ber_extension(av[1]))
		{
			ft_putendl_fd("Error: Invalid file extension. Use .ber files only.",
				2);
			exit(EXIT_FAILURE);
		}
        ft_memset(&map, 0, sizeof(t_map));
		get_map(av[1], &map);
	}
    else
    {
        ft_putendl_fd("Usage: ./so_long map.ber", 2);
        exit(EXIT_FAILURE);
    }
	start_game(&map);
    return (0);
}
