/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_zeros.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:49:11 by vkurkela          #+#    #+#             */
/*   Updated: 2020/01/28 21:37:38 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_zeros(int max, int *len, int *bytes)
{
	int i;
	int count;

	i = 0;
	count = max - *len;
	if (max < *len)
		return ;
	while (i < count)
	{
		ft_putchar('0');
		*bytes += 1;
		*len += 1;
		i++;
	}
}
