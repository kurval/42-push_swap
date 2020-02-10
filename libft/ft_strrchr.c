/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:27:55 by vkurkela          #+#    #+#             */
/*   Updated: 2019/10/25 16:25:18 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*begin;

	i = ft_strlen(s);
	begin = (char*)s;
	if (c == '\0')
		return (&begin[i]);
	while (i >= 0)
	{
		if (s[i] == c)
			return (&begin[i]);
		i--;
	}
	return (NULL);
}
