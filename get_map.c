/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:45:48 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/17 02:04:05 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	has_ber_extension(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	return (strncmp(filename + (len - 4), ".ber") == 0);
}

static t_list	*read_map(int fd)
{
	t_list	*map_list;
	char	*line;

	map_list = NULL;
	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(&map_list, ft_lstnew(line));
		line = get_next_line(fd);
	}
	return (map_list);
}

static char	**list_to_array(t_list *lst, int height)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc((height + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	while (lst)
	{
		map[i++] = lst->content;
		lst = lst->next;
	}
	map[i] = NULL;
	return (map);
}

void	get_map(const char *filename, t_map *map)
{
    int		fd;
    t_list	*map_list;

    if (!has_ber_extension(filename))
        exit(EXIT_FAILURE);
    fd = open(filename, O_RDONLY);
	if (fd < 0)
        exit(EXIT_FAILURE);
    map_list = read_map(fd);
    close(fd);
    map->height = ft_lstsize(map_list);
    map->grid = list_to_array(map_list, map->height);
    if (!map->grid || map->height == 0)
    {
        ft_lstclear(&map_list, NULL);
        exit(EXIT_FAILURE);
    }
    map->width = ft_strlen(map->grid[0]);
    ft_lstclear(&map_list, NULL);
    check_map_validity(map);
}
