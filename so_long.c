/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:23:59 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/20 13:20:58 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(char **map, int width, int height)
{
	void	*mlx;

	(void)map;
	mlx = mlx_init();
	mlx_new_window(mlx, width * TILE_SIZE, height * TILE_SIZE, "so_long");
	// You'll draw the map here using mlx_put_image_to_window()
	mlx_loop(mlx);
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
	start_game(map.grid, map.width, map.height);
    return (0);
}
