/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:20:48 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/04 09:54:12 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long double	round(int precision, long double f)
{
	long double	rounding;
	int			d;

	rounding = 0.5;
	if (f < 0)
		rounding *= -1;
	d = 0;
	while (d++ < precision)
		rounding /= 10.0;
	return (rounding);
}

char				*ft_ftoa(long double f, int precision, int dot)
{
	unsigned long long	value;
	char				*firstpart;
	char				*decimal;
	char				*result;
	int					i;

	f = f + round(precision, f);
	f *= (f < 0) ? -1 : 1;
	value = f;
	firstpart = ft_itoa(value);
	f = precision ? (f - value) : 0;
	decimal = ft_strnew(precision + 2);
	decimal[0] = (dot) ? '.' : '\0';
	i = 1;
	while (precision-- > 0)
	{
		f *= 10;
		value = f;
		f -= value;
		decimal[i++] = value + '0';
	}
	result = ft_strjoin(firstpart, decimal);
	free(decimal);
	free(firstpart);
	return (result);
}
