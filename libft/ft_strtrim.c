/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:33:39 by vkurkela          #+#    #+#             */
/*   Updated: 2019/10/29 09:36:33 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*check_whitespaces(char *s1, char const *s2)
{
	int i;
	int j;
	int k;

	i = 0;
	j = ft_strlen(s2) - 1;
	k = 0;
	while (s2[i] == ' ' || s2[i] == '\n' || s2[i] == '\t')
		i++;
	while (s2[j] == ' ' || s2[j] == '\n' || s2[j] == '\t')
		j--;
	while (i <= j)
		s1[k++] = s2[i++];
	s1[k] = '\0';
	return (s1);
}

static int	calc_len(char const *s)
{
	int i;
	int j;
	int k;

	i = 0;
	j = ft_strlen(s) - 1;
	k = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	while (i <= j)
	{
		i++;
		k++;
	}
	return (k);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	char	*trim;
	int		len;

	i = 0;
	len = 0;
	if (s)
	{
		len = calc_len(s);
		if (!(trim = (char*)malloc(sizeof(*trim) * len + 1)))
			return (NULL);
		check_whitespaces(trim, s);
		return (trim);
	}
	return (NULL);
}
