/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:55:08 by vkurkela          #+#    #+#             */
/*   Updated: 2019/10/21 14:29:51 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long value;

	value = n;
	if (value < 0)
	{
		ft_putchar('-');
		value = -value;
	}
	if (value / 10)
	{
		ft_putnbr(value / 10);
	}
	ft_putchar(value % 10 + '0');
}
