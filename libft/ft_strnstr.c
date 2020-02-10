/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 09:41:13 by vkurkela          #+#    #+#             */
/*   Updated: 2019/10/29 15:16:48 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	char	*begin;
	size_t	count;

	j = 0;
	count = 0;
	begin = (char*)haystack;
	if (needle[j] == '\0')
		return (begin);
	while (begin[j] != '\0' && count < (len))
	{
		i = 0;
		while (begin[i] == needle[i] && begin[i] && \
				needle[i] && count < (len))
		{
			i++;
			count++;
		}
		if (needle[i] == '\0')
			return (begin);
		begin = &begin[j + 1];
		count = (count - i) + 1;
	}
	return (0);
}
