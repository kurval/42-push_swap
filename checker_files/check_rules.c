/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:12:35 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/25 10:19:04 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	check_rules3(t_rules *rules)
{
	if (ft_strncmp_end(rules->data, "ra", 2) &&\
			ft_strncmp_end(rules->data, "rb", 2) &&\
			ft_strncmp_end(rules->data, "rr", 2) &&\
			ft_strncmp_end(rules->data, "pa", 2) &&\
			ft_strncmp_end(rules->data, "pb", 2) &&\
			ft_strncmp_end(rules->data, "sa", 2) &&\
			ft_strncmp_end(rules->data, "sb", 2) &&\
			ft_strncmp_end(rules->data, "ss", 2))
		return (0);
	else
		return (1);
}

static int	check_rules2(t_rules *rules)
{
	if (ft_strncmp_end(rules->data, "rra", 3) &&\
			ft_strncmp_end(rules->data, "rrb", 3) &&\
			ft_strncmp_end(rules->data, "rrr", 3))
		return (0);
	else
		return (1);
}

int			check_rules(t_rules *rules)
{
	int len;

	len = 0;
	while (rules)
	{
		len = ft_strlen(rules->data);
		if ((len == 3 && !check_rules2(rules)) ||\
				(len == 2 && !check_rules3(rules)) ||\
				(len != 3 && len != 2))
			return (0);
		rules = rules->next;
	}
	return (1);
}
