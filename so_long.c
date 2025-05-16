/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:23:59 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/17 01:05:12 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	**map;

	if (ac > 1)
	{
		if (!has_ber_extension(av[1]))
		{
			ft_putendl_fd("Error: Invalid file extension. Use .ber files only.",
				2);
			exit(EXIT_FAILURE);
		}
		map = get_map(av[1]);
	}
}
