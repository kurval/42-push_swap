/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 21:56:19 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/19 16:20:46 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	move_b(t_stack **root_a, t_stack **root_b)
{
	int tmp;

	tmp = (*root_b)->data;
	while ((*root_b)->tag)
		push_ab(root_b, root_a);
	while (!is_empty(*root_b))
	{
		tmp = (*root_b)->data;
		if (tmp < (*root_a)->data)
			push_ab(root_b, root_a);
		else
		{
			rotate(root_b);
			while ((*root_a) && tmp > (*root_a)->data)
				push_ab(root_a, root_b);
			reverse_rotate(root_b);
			push_ab(root_b, root_a);
		}
	}
}

static void	move_partitions(t_stack **root_a, t_stack **root_b,\
		int pivot, int *size, int partition)
{
	int round;
	int b;
	
	round = (*root_a)->data;
	rotate(root_a);
	b = 0;
	while ((*root_a)->data != round)
	{
		if ((*root_a)->data < pivot)
		{
			push_ab(root_a, root_b);
			(*root_b)->chunk = partition;
			*size -= 1;
			b++;
		}
		else
			rotate(root_a);
	}
	push_ab(root_a, root_b);
	*size -= 1;
	(*root_b)->tag = 1;
	(*root_b)->chunk = partition;
}

void		quick_sort(t_stack **root_a, t_stack **root_b, int size, int mid)
{
	int pivot;
	int chunk;

	chunk = 0;
	while (!is_empty(*root_a) && size > 3)
	{
		chunk += 1;
		mid = calc_mid(root_a);
		pivot = (mid) ? mid : (*root_a)->data;
		move_partitions(root_a, root_b, pivot, &size, chunk);
		mid = 0;
	}
	if (size == 3)
		sort_three(root_a);
	else if (size == 2)
		((*root_a)->data > (*root_a)->next->data) ? swap(root_a) : 0;
	move_b(root_a, root_b);
}