/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:47:30 by vkurkela          #+#    #+#             */
/*   Updated: 2019/10/28 16:18:57 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	int				i;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	i = 0;
	while (i < (int)n)
	{
		if (s[i] != (unsigned char)c)
		{
			d[i] = s[i];
			i++;
		}
		else
		{
			d[i] = s[i];
			return (&d[i + 1]);
		}
	}
	return (NULL);
}
