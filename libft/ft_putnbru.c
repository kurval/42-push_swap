/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:55:08 by vkurkela          #+#    #+#             */
/*   Updated: 2020/01/26 20:28:44 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbru(unsigned long long value, int *bytes)
{
	if (value < 0)
	{
		ft_putchar('-');
		value = -value;
		*bytes = *bytes + 1;
	}
	if (value / 10)
	{
		ft_putnbru(value / 10, bytes);
	}
	*bytes = *bytes + 1;
	ft_putchar(value % 10 + '0');
}
