/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:51:02 by zsalih            #+#    #+#             */
/*   Updated: 2025/01/08 00:08:33 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putpad(int count, char padchr)
{
	int	i;

	i = 0;
	while (i < count)
	{
		write(1, &padchr, 1);
		i++;
	}
	return (i);
}

int	set_pad_width(int len, t_format *fmt)
{
	int	pad_width;

	if (fmt->precision > len)
		pad_width = fmt->width - fmt->precision;
	else
		pad_width = fmt->width - len;
	if (pad_width < 0)
		pad_width = 0;
	return (pad_width);
}
