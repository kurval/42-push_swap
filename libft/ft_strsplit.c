/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:35:12 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/02 11:43:28 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_words(const char *str, char c)
{
	int words;

	words = 0;
	if (*str != c && *str)
		words++;
	while (*str)
	{
		while (*str == c)
		{
			str++;
			if (*str != c && *str)
				words++;
		}
		str++;
	}
	return (words);
}

static int		letters(const char *str, char c)
{
	int len;

	len = 0;
	while (*str != c && *str)
	{
		len++;
		str++;
	}
	return (len);
}

static char		**allocate_tab(char const *s, char c)
{
	char	**tab;

	if (!s || (!(tab = (char **)malloc(sizeof(char *) * \
						(ft_words(s, c) + 2)))))
		return (NULL);
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	int		j;
	int		i;
	char	**tab;

	j = 1;
	i = 0;
	tab = allocate_tab(s, c);
	tab[0] = ft_strnew(1);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			if (!(tab[j] = (char *)malloc(sizeof(char) * (letters(s, c) + 1))))
				return (NULL);
			while (*s && *s != c)
				tab[j][i++] = (char)*s++;
			tab[j][i] = '\0';
			j++;
			i = 0;
		}
	}
	tab[j] = NULL;
	return (tab);
}
