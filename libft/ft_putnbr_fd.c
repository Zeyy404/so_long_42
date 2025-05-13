/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:05:39 by zsalih            #+#    #+#             */
/*   Updated: 2024/12/25 15:24:48 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	nb_mod;
	int		is_min;

	is_min = 0;
	nb_mod = 0;
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		n = 214748364;
		is_min = 1;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n / 10 > 0)
	{
		ft_putnbr_fd((n / 10), fd);
	}
	nb_mod = (n % 10) + '0';
	ft_putchar_fd(nb_mod, fd);
	if (is_min == 1)
		ft_putchar_fd('8', fd);
}
