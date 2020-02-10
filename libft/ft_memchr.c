/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 09:20:54 by vkurkela          #+#    #+#             */
/*   Updated: 2019/10/24 09:46:41 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*b;
	unsigned char	*first;
	int				i;

	b = (unsigned char*)s;
	i = 0;
	while (i < (int)n)
	{
		if (b[i] == (unsigned char)c)
		{
			first = &b[i];
			return (first);
		}
		i++;
	}
	return (NULL);
}
