/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:31:33 by vkurkela          #+#    #+#             */
/*   Updated: 2020/01/26 16:21:16 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	num_len(unsigned long long value, int base)
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

char				*ft_itoa_base(unsigned long long value, int base)
{
	int					size;
	unsigned long long	nbr;
	char				*res;
	char				*str_base;

	nbr = value;
	str_base = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (NULL);
	size = num_len(nbr, base);
	if (!(res = (char*)malloc(sizeof(*res) * (size + 1))))
		return (NULL);
	res[size--] = '\0';
	res[0] = (nbr < 0 && base == 10 ? '-' : '0');
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		res[size--] = str_base[nbr % base];
		nbr /= base;
	}
	return (res);
}
