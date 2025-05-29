/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 01:06:30 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/29 08:58:56 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_rectangular(t_map *map)
{
	int	i;

	i = 0;
	while (map->grid[i])
	{
		if ((int)ft_strlen(map->grid[i]) != map->width)
			return (0);
		i++;
	}
	return (1);
}

static int	check_characters(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->grid[++i])
	{
		j = 0;
		while (map->grid[i][++j])
		{
			if (map->grid[i][j] == 'P')
				init_player(map, i, j);
			else if (map->grid[i][j] == 'E')
				map->exit_count++;
			else if (map->grid[i][j] == 'C')
				map->collectible_count++;
			else if (map->grid[i][j] == 'X')
				init_enemy(map, i, j);
			else if (map->grid[i][j] != '1' && map->grid[i][j] != '0')
				return (0);
		}
	}
	return (1);
}

static int	check_required_elements(t_map *map)
{
	if (map->player_count != 1 || map->exit_count != 1
		|| map->collectible_count < 1)
		return (0);
	return (1);
}

static int	check_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	check_map_validity(t_map *map)
{
	if (map->width > MAX_MAP_WIDTH || map->height > MAX_MAP_HEIGHT)
		error_exit("Error: Map size exceeds maximum limits\n", map);
	if (!check_rectangular(map))
		error_exit("Erorr: Map is not rectangular\n", map);
	if (!check_characters(map))
		error_exit("Erorr: Invalid characters found\n", map);
	if (!check_required_elements(map))
		error_exit("Error: Missing required elements\n", map);
	if (!check_walls(map))
		error_exit("Error: Map is not surrounded by walls\n", map);
	if (!check_reachability(map))
		error_exit("Erorr: Map is unsolvable\n", map);
}
