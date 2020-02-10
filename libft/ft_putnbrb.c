/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:55:08 by vkurkela          #+#    #+#             */
/*   Updated: 2020/01/29 14:05:51 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrb(long long value, int *bytes)
{
	if (value == -9223372036854775807 - 1)
	{
		ft_putstrb("-9223372036854775808", bytes);
		return ;
	}
	if (value < 0)
	{
		ft_putchar('-');
		value = -value;
		*bytes = *bytes + 1;
	}
	if (value / 10)
		ft_putnbrb(value / 10, bytes);
	*bytes = *bytes + 1;
	ft_putchar(value % 10 + '0');
}
