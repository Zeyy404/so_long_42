/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starfield.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 21:33:52 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/26 01:06:00 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_starfield(t_mlx *mlx)
{
	mlx->num_stars = MAX_STARS;
	for (int i = 0; i < mlx->num_stars; i++)
	{
		mlx->stars[i].x = rand() % mlx->floor_texture.width;
		mlx->stars[i].y = rand() % mlx->floor_texture.height;
		mlx->stars[i].brightness = 200 + rand() % 56;
		mlx->stars[i].twinkle_freq = 0.02f + ((rand() % 100) / 5000.0f);
		mlx->stars[i].twinkle_phase = (rand() % 628) / 100.0f;
	}
}

void	draw_starfield(t_mlx *mlx)
{
	t_star	*star;
	int		twinkle;
	int		color;
	int		idx;
	int		i;
	float	t;

	i = 0;
	while (i < mlx->num_stars)
	{
		star = &mlx->stars[i];
		t = mlx->frame_count * star->twinkle_freq + star->twinkle_phase;
		twinkle = star->brightness + (int)(40.0f * sinf(t));
		if (twinkle > 255)
			twinkle = 255;
		if (twinkle < 0)
			twinkle = 0;
		color = (twinkle << 16) | (twinkle << 8) | twinkle;
		idx = star->y * (mlx->floor_texture.line_len / 4) + star->x;
		if (idx >= 0 && idx < (mlx->floor_texture.width
				* mlx->floor_texture.height))
			mlx->floor_texture.pixels[idx] = color;
		i++;
	}
}
