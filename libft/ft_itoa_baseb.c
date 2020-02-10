/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_baseb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:31:33 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/03 10:41:31 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			print_res(char *res, int *bytes, char flag)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(res);
	if (len < 8 && flag == 'b')
	{
		while (i++ < (8 - len))
			ft_putcharb('0', bytes);
	}
	ft_putstrb(res, bytes);
	free(res);
}

static unsigned int	num_len(unsigned long long value, int base)
{
	unsigned long long	size;

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

int					ft_itoa_baseb(unsigned long long value, \
		int base, int *bytes, char flag)
{
	unsigned long long	size;
	char				*res;
	char				*str_base;

	str_base = (flag == 'x' || flag == 'p' ? \
	"0123456789abcdef" : "0123456789ABCDEF");
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
	print_res(res, bytes, flag);
	return (1);
}
