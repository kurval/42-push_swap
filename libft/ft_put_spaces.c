/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:49:11 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/03 16:29:07 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_spaces(int min, int size, int *bytes)
{
	int i;

	i = 0;
	if (min < size)
		return ;
	while (i < (min - size))
	{
		ft_putchar(' ');
		*bytes += 1;
		i++;
	}
}
