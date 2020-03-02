/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:02:27 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/02 11:44:05 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	count_rules(t_rules *rules)
{
	int		size;
	t_rules *current;

	current = rules;
	size = 0;
	while (current)
	{
		current = current->next;
		size++;
	}
	return (size);
}
