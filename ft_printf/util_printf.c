/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:54:06 by zsalih            #+#    #+#             */
/*   Updated: 2025/01/09 14:36:40 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_format(t_format *fmt)
{
	fmt->flag_minus = 0;
	fmt->flag_zero = 0;
	fmt->flag_hash = 0;
	fmt->flag_space = 0;
	fmt->flag_plus = 0;
	fmt->width = 0;
	fmt->precision = -1;
	fmt->specifier = '\0';
	fmt->f = NULL;
}

void	assign_f(t_format *fmt)
{
	if (fmt->specifier == 'c')
		fmt->f = ft_putchr;
	else if (fmt->specifier == 's')
		fmt->f = ft_putstr;
	else if (fmt->specifier == 'p')
		fmt->f = ft_putptr;
	else if (fmt->specifier == 'd' || fmt->specifier == 'i')
		fmt->f = ft_putint;
	else if (fmt->specifier == 'u')
		fmt->f = ft_putuint;
	else if (fmt->specifier == 'x' || fmt->specifier == 'X')
		fmt->f = ft_puthex;
	else
		fmt->f = NULL;
}

void	set_flag(const char *format, int *i, t_format *fmt)
{
	if (format[*i] == '-')
		fmt->flag_minus = 1;
	else if (format[*i] == '+')
		fmt->flag_plus = 1;
	else if (format[*i] == '0')
		fmt->flag_zero = 1;
	else if (format[*i] == '#')
		fmt->flag_hash = 1;
	else if (format[*i] == ' ')
		fmt->flag_space = 1;
}

void	check_flags(const char *format, int *i, t_format *fmt)
{
	(*i)++;
	while (format[*i] == '-' || format[*i] == '+' || format[*i] == ' '
		|| format[*i] == '#' || format[*i] == '0')
	{
		set_flag(format, i, fmt);
		(*i)++;
	}
	if (ft_isdigit(format[*i]))
	{
		fmt->width = ft_atoi(&format[*i]);
		while (ft_isdigit(format[*i]))
			(*i)++;
	}
	if (format[*i] == '.')
	{
		(*i)++;
		if (ft_isdigit(format[*i]))
		{
			fmt->precision = ft_atoi(&format[*i]);
			while (ft_isdigit(format[*i]))
				(*i)++;
		}
		else
			fmt->precision = 0;
	}
}

int	parse_format(const char *format, va_list args, int *i, t_format *fmt)
{
	int	count;

	count = 0;
	check_flags(format, i, fmt);
	if (!format[*i])
		return (0);
	if (format[*i] == '%')
	{
		(*i)++;
		return (ft_putpct(fmt));
	}
	fmt->specifier = format[*i];
	assign_f(fmt);
	if (fmt->f)
	{
		(*i)++;
		return (fmt->f(args, fmt));
	}
	if (format[*i])
		count += write(1, &format[(*i)++], 1);
	return (count);
}
