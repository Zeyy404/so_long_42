/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:39:15 by zsalih            #+#    #+#             */
/*   Updated: 2025/01/08 14:29:23 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_format
{
	int		flag_minus;
	int		flag_zero;
	int		flag_hash;
	int		flag_space;
	int		flag_plus;
	int		width;
	int		precision;
	char	specifier;
	int		(*f)(va_list, struct s_format *);
}			t_format;

int			ft_printf(const char *format, ...);
int			ft_putchr(va_list args, t_format *fmt);
int			ft_putstr(va_list args, t_format *fmt);
int			ft_putptr(va_list args, t_format *fmt);
int			ft_putint(va_list args, t_format *fmt);
int			ft_putuint(va_list args, t_format *fmt);
int			ft_puthex(va_list args, t_format *fmt);
int			ft_putpct(t_format *fmt);
int			parse_format(const char *format, va_list args, int *i,
				t_format *fmt);
void		check_flags(const char *format, int *i, t_format *fmt);
void		set_flag(const char *format, int *i, t_format *fmt);
void		assign_f(t_format *fmt);
void		init_format(t_format *fmt);
int			putpad(int count, char padchr);
int			set_pad_width(int len, t_format *fmt);
int			ft_isdigit(int c);
int			ft_atoi(const char *nptr);
size_t		ft_strlen(const char *s);

#endif