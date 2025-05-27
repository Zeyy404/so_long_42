/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:39:33 by zsalih            #+#    #+#             */
/*   Updated: 2025/01/08 00:05:08 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchr(va_list args, t_format *fmt)
{
	char	c;
	int		count;
	int		pad_width;

	c = (char)va_arg(args, int);
	if (fmt->width > 1)
		pad_width = fmt->width - 1;
	else
		pad_width = 0;
	count = 0;
	if (!fmt->flag_minus)
		count += putpad(pad_width, ' ');
	count += write(1, &c, 1);
	if (fmt->flag_minus)
		count += putpad(pad_width, ' ');
	return (count);
}
