/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:17:25 by vkurkela          #+#    #+#             */
/*   Updated: 2019/10/25 16:30:32 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long value;

	value = n;
	if (value < 0)
	{
		ft_putchar_fd('-', fd);
		value = -value;
	}
	if (value / 10)
	{
		ft_putnbr_fd(value / 10, fd);
	}
	ft_putchar_fd(value % 10 + '0', fd);
}
