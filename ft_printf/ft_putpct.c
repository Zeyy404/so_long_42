/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:02:29 by zsalih            #+#    #+#             */
/*   Updated: 2025/01/08 16:06:30 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpct(t_format *fmt)
{
	int	count;
	int	pad_width;

	count = 0;
	if (fmt->width)
		pad_width = fmt->width - 1;
	else
		pad_width = 0;
	if (!fmt->flag_minus)
	{
		if (fmt->flag_zero)
			count += putpad(pad_width, '0');
		else
			count += putpad(pad_width, ' ');
	}
	count += write(1, "%", 1);
	if (fmt->flag_minus)
		count += putpad(pad_width, ' ');
	return (count);
}
