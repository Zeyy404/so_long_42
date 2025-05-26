/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:23:59 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/26 11:42:13 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void exit_game(t_mlx *mlx)
{
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	free_textures(mlx);
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
	if (!init_textures(&mlx))
	{
		ft_putendl_fd("Error: Failed to load textures\n", 2);
		exit(1);
	}
	init_starfield(&mlx);
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
