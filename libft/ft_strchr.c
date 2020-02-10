/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:47:18 by vkurkela          #+#    #+#             */
/*   Updated: 2019/10/25 16:33:53 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*begin;

	i = 0;
	begin = (char*)s;
	while (s[i])
	{
		if (s[i] == c)
			return (&begin[i]);
		i++;
	}
	if (c == '\0' && s[i] == '\0')
		return (&begin[i]);
	return (NULL);
}
