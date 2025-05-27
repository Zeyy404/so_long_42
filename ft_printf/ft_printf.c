/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:39:04 by zsalih            #+#    #+#             */
/*   Updated: 2025/01/09 13:58:37 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_format	*fmt;
	va_list		args;
	int			count;
	int			i;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	fmt = malloc(sizeof(t_format));
	if (!fmt)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		init_format(fmt);
		if (format[i] == '%')
			count += parse_format(format, args, &i, fmt);
		else
			count += write(1, &format[i++], 1);
	}
	va_end(args);
	free(fmt);
	return (count);
}
