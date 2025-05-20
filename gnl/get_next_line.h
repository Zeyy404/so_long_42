/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:21:31 by zsalih            #+#    #+#             */
/*   Updated: 2025/05/20 13:37:41 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

char	*get_next_line(int fd);

#endif
