/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 01:48:17 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/17 01:50:12 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_map(t_map *map)
{
	int i;

	if (!map || !map->grid)
		return;
	i = 0;
	while (map->grid[i])
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

void error_exit(const char *message, t_map *map)
{
    if (map)
        free_map(map);
    ft_putendl_fd(message, 2);
    exit(EXIT_FAILURE);
}
