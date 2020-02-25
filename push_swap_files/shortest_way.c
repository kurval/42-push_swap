/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_way.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:34:52 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/25 10:27:43 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	calc_size(t_stack *root)
{
	t_stack *current;
	int		size;

	size = 0;
	current = root;
	while (current)
	{
		current = current->next;
		size++;
	}
	return (size);
}

int			shortest_way(t_stack *root, int value)
{
	int		size;
	int		moves;
	int		pos;
	t_stack *current;
	int		mid;

	pos = 0;
	moves = 0;
	size = calc_size(root);
	mid = size / 2;
	current = root;
	while (current->data != value)
	{
		current = current->next;
		pos++;
	}
	if (pos <= mid)
		moves += pos;
	else
		moves = (-1 * (size - pos));
	return (moves);
}
