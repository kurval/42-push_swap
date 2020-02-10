/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_haystackhaystack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:49:47 by vkurkela          #+#    #+#             */
/*   Updated: 2019/10/28 16:28:19 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*begin;

	j = 0;
	begin = (char*)haystack;
	if (needle[j] == '\0')
		return (begin);
	while (begin[j] != '\0')
	{
		i = 0;
		while (begin[i] == needle[i] && begin[i] && needle[i])
			i++;
		if (needle[i] == '\0')
			return (begin);
		begin = &begin[j + 1];
	}
	return (0);
}
