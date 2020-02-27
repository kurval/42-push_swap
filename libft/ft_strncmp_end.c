/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 00:17:39 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/27 15:32:55 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp_end(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while ((str1[i] != '\0' && str2[i] != '\0') && \
			str1[i] == str2[i] && i < (int)(n - 1))
		i++;
	if ((str1[i] == str2[i] || (int)n == 0) &&\
		ft_strlen(s1) == ft_strlen(s2))
		return (0);
	else
		return (1);
}
