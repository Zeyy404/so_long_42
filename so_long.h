/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:22:20 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/13 12:08:10 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_map_info
{
	int			player_count;
	int			exit_count;
	int			collectible_count;
	t_position	player_pos;
}				t_map_info;

int	has_ber_extension(const char *filename);

#endif