/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rev_order.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:22:38 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/20 11:28:29 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		check_rev_order(t_stack *root_b)
{
	t_stack *future;

	if (!(is_empty(root_b)))
		return (0);
	while (root_b)
	{
		future = root_b->next;
		while (future)
		{
			if (root_b->data < future->data)
				return (0);
			future = future->next;
		}
		root_b = root_b->next;
	}
	return (1);
}
