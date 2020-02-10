/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:31:27 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/03 13:46:36 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(long long value)
{
	int		l;

	l = 1;
	if (value < 0)
		l++;
	while (value / 10)
	{
		value = value / 10;
		l++;
	}
	return (l);
}
