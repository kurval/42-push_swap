/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:22:38 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/28 10:37:22 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		check_order(t_stack *root_a, t_stack *root_b)
{
	t_stack *future;

	if (!(is_empty(root_b)))
		return (0);
	while (root_a)
	{
		future = root_a->next;
		while (future)
		{
			if (root_a->data > future->data)
				return (0);
			future = future->next;
		}
		root_a = root_a->next;
	}
	return (1);
}
