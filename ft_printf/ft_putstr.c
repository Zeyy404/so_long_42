/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:39:48 by zsalih            #+#    #+#             */
/*   Updated: 2025/01/08 19:23:21 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(va_list args, t_format *fmt)
{
	int		count;
	char	*str;
	int		pad_width;
	int		len;

	str = va_arg(args, char *);
	count = 0;
	if (str == NULL)
		str = "(null)";
	if (fmt->precision == 0)
		len = 0;
	else if (fmt->precision > 0 && fmt->precision < (int)ft_strlen(str))
		len = fmt->precision;
	else
		len = (int)ft_strlen(str);
	pad_width = fmt->width - len;
	if (pad_width < 0)
		pad_width = 0;
	if (!fmt->flag_minus)
		count += putpad(pad_width, ' ');
	count += write(1, str, len);
	if (fmt->flag_minus)
		count += putpad(pad_width, ' ');
	return (count);
}
