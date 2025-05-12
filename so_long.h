/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:22:20 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/12 13:23:42 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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

#endif