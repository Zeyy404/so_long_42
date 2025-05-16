/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 02:04:58 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/17 03:34:49 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_grid(char **grid, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(grid[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	free_grid(char **grid, int height)
{
	int i = 0;
	while (i < height)
		free(grid[i++]);
	free(grid);
}

static void	flood_fill(t_map *map, t_ff *ff_info, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return ;
	if (ff_info->grid[y][x] == '1' || ff_info->grid[y][x] == 'V')
		return ;
	if (ff_info->grid[y][x] == 'C')
		ff_info->collectibles_found++;
	if (ff_info->grid[y][x] == 'E')
		ff_info->exit_reached = 1;
	ff_info->grid[y][x] = 'V';
	flood_fill(map, ff_info, x + 1, y);
	flood_fill(map, ff_info, x - 1, y);
	flood_fill(map, ff_info, x, y + 1);
	flood_fill(map, ff_info, x, y - 1);
}

int	check_reachability(t_map *map)
{
	t_ff ff_info;

	ff_info.collectibles_found = 0;
	ff_info.exit_reached = 0;
	ff_info.grid = copy_grid(map->grid, map->height);
	if (!ff_info.grid)
		return (0);
	flood_fill(map, &ff_info, map->player_pos.x, map->player_pos.y);
	if (ff_info.collectibles_found != map->collectible_count
		|| ff_info.exit_reached == 0)
	{
		free_grid(ff_info.grid, map->height);
		return (0);
	}
	free_grid(ff_info.grid, map->height);
	return (1);
}
