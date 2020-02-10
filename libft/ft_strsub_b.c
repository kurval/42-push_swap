/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 10:08:58 by vkurkela          #+#    #+#             */
/*   Updated: 2020/01/28 19:24:01 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strsub_b(char const *s, unsigned intstart, \
		size_t len, int *bytes)
{
	char			*sub;
	unsigned int	i;

	i = 0;
	if (!s || !(sub = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (i < len)
	{
		sub[i] = s[i + intstart];
		i++;
	}
	sub[i] = '\0';
	ft_putstrb(sub, bytes);
	free(sub);
	return (1);
}
