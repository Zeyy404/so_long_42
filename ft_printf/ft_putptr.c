/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:40:11 by zsalih            #+#    #+#             */
/*   Updated: 2025/01/09 15:29:07 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printptr(char *buffer, int len, int is_zero, t_format *fmt)
{
	int	count;
	int	pad_width;

	count = 0;
	if (is_zero)
		pad_width = set_pad_width(len, fmt);
	else
		pad_width = set_pad_width(len + 2, fmt);
	if (!fmt->flag_minus)
		count += putpad(pad_width, ' ');
	if (is_zero)
		count += write(1, "0x0", 3);
	else
		count += write(1, "0x", 2);
	if (!is_zero)
	{
		while (--len >= 0)
			count += write(1, &buffer[len], 1);
	}
	if (fmt->flag_minus)
		count += putpad(pad_width, ' ');
	return (count);
}

int	ft_putptr(va_list args, t_format *fmt)
{
	unsigned long	ptr;
	char			buffer[18];
	int				len;
	int				remainder;
	int				is_zero;

	ptr = (unsigned long)va_arg(args, void *);
	is_zero = 0;
	if (ptr == 0)
	{
		is_zero = 1;
		return (printptr("0x0", 3, is_zero, fmt));
	}
	len = 0;
	while (ptr > 0)
	{
		remainder = ptr % 16;
		if (remainder < 10)
			buffer[len++] = remainder + '0';
		else
			buffer[len++] = remainder - 10 + 'a';
		ptr /= 16;
	}
	return (printptr(buffer, len, is_zero, fmt));
}
