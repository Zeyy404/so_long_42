/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starfield.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 21:33:52 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/29 09:16:32 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_starfield(t_mlx *mlx)
{
	int	i;

	mlx->num_stars = MAX_STARS;
	i = 0;
	while (i < mlx->num_stars)
	{
		mlx->stars[i].x = rand() % mlx->floor_texture.width;
		mlx->stars[i].y = rand() % mlx->floor_texture.height;
		i++;
	}
}

void	draw_starfield(t_mlx *mlx)
{
	t_star	*star;
	int		color;
	int		idx;
	int		i;

	i = 0;
	while (i < mlx->num_stars)
	{
		star = &mlx->stars[i];
		color = 0xFFFFFF;
		idx = star->y * (mlx->floor_texture.line_len / 4) + star->x;
		if (idx >= 0 && idx < (mlx->floor_texture.width
				* mlx->floor_texture.height))
			mlx->floor_texture.pixels[idx] = color;
		i++;
	}
}
