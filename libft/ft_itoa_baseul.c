/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_baseul.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:05:39 by vkurkela          #+#    #+#             */
/*   Updated: 2020/01/16 10:06:35 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	num_len(long value, int base)
{
	int	size;

	size = 1;
	if (value < 0 && base == 10)
		size++;
	while (value / base)
	{
		size++;
		value /= base;
	}
	return (size);
}

char				*ft_itoa_baseul(unsigned long value, int base)
{
	int				size;
	char			*res;
	char			*str_base;

	str_base = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (0);
	size = num_len(value, base);
	if (!(res = (char*)malloc(sizeof(*res) * (size + 1))))
		return (0);
	res[size--] = '\0';
	res[0] = (value < 0 && base == 10 ? '-' : '0');
	if (value < 0)
		value = -value;
	while (value > 0)
	{
		res[size--] = str_base[value % base];
		value /= base;
	}
	return (res);
}
