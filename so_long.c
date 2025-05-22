/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:23:59 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/22 15:33:22 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_map *map)
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		exit(1);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, map->width * TILE_SIZE, map->height * TILE_SIZE, "so_long");
	if (!mlx.win_ptr)
		exit(1);
	mlx.map = map;
	setup_hooks(&mlx);
	render_map(&mlx);
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
