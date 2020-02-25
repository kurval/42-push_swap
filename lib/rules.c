/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:40:35 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/25 10:25:54 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int	is_rules(t_rules *rules)
{
	return (!rules);
}

void		free_rules(t_rules *rules)
{
	t_rules *temp;

	temp = NULL;
	if (is_rules(rules))
		return ;
	while (rules)
	{
		temp = rules;
		rules = rules->next;
		free(temp);
	}
}

t_rules		*new_rule(char *data)
{
	t_rules *new_node;

	new_node = (t_rules*)malloc(sizeof(t_rules));
	ft_strcpy(new_node->data, data);
	new_node->next = NULL;
	return (new_node);
}

void		push_rules(t_rules **rules, char *data)
{
	t_rules	*node;
	t_rules *current;

	node = new_rule(data);
	if (is_rules(*rules))
	{
		*rules = node;
		return ;
	}
	else
		current = *rules;
	while (current->next != NULL)
		current = current->next;
	current->next = node;
}

void		print_rules(t_rules *rules)
{
	t_rules *current;

	current = rules;
	while (current)
	{
		ft_printf("%s\n", current->data);
		current = current->next;
	}
}
