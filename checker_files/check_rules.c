/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:12:35 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/16 19:31:52 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int check_rules3(char **rules, int *i)
{
    if	(ft_strncmp_end(rules[*i], "ra", 2) &&\
        ft_strncmp_end(rules[*i], "rb", 2) &&\
        ft_strncmp_end(rules[*i], "rr", 2) &&\
        ft_strncmp_end(rules[*i], "pa", 2) &&\
        ft_strncmp_end(rules[*i], "pb", 2) &&\
        ft_strncmp_end(rules[*i], "sa", 2) &&\
        ft_strncmp_end(rules[*i], "sb", 2) &&\
        ft_strncmp_end(rules[*i], "ss", 2))
        return (0);
    else
        return (1);
}

int check_rules2(char **rules, int *i)
{
    if	(ft_strncmp_end(rules[*i], "rra", 3) &&\
        ft_strncmp_end(rules[*i], "rrb", 3) &&\
        ft_strncmp_end(rules[*i], "rra", 3))
        return (0);
    else
        return (1);
}

int		check_rules(char **rules)
{
	int i;
    int len;

	i = 0;
    len = 0;
	while (rules[i])
	{
        len = ft_strlen(rules[i]);
		if ((len == 3 && !check_rules2(rules, &i)) ||\
        (len == 2 && !check_rules3(rules, &i)) ||\
        (len != 3 && len != 2))
            return (0);
		i++;
	}
	return (1);
}
