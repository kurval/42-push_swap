/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlenu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:09:12 by vkurkela          #+#    #+#             */
/*   Updated: 2020/01/26 20:17:37 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlenu(unsigned long long value)
{
	int		l;

	l = 1;
	while (value / 10)
	{
		value = value / 10;
		l++;
	}
	return (l);
}
