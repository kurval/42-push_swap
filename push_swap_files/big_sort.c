/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 21:56:19 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/20 19:58:25 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	move_b(t_stack **root_a, t_stack **root_b)
{
	int tmp;
	int pivot;

	tmp = (*root_b)->data;
	while ((*root_b)->tag)
		push_ab(root_b, root_a);
	pivot = (*root_b)->data;
	rotate(root_b);
	while ((*root_a) && (*root_b)->data != pivot)
	{
		tmp = (*root_b)->data;
		if (tmp < (*root_a)->data && tmp > pivot)
			push_ab(root_b, root_a);
		else if (tmp < pivot)
			rotate(root_b);
		else
		{
			rotate(root_b);
			while ((*root_a) && tmp > (*root_a)->data)
				push_ab(root_a, root_b);
			reverse_rotate(root_b);
			push_ab(root_b, root_a);
		}
	}
	push_ab(root_b, root_a);
}

static void	move_partitions(t_stack **root_a, t_stack **root_b,\
		int pivot, int *size, int partition)
{
	int round;
	
	round = (*root_a)->data;
	rotate(root_a);
	while ((*root_a)->data != round)
	{
		if ((*root_a)->data < pivot)
		{
			push_ab(root_a, root_b);
			(*root_b)->chunk = partition;
			*size -= 1;
		}
		else
			rotate(root_a);
	}
	!(*root_a)->med ? (*root_b)->tag = 1 : 0;
	push_ab(root_a, root_b);
	*size -= 1;
	(*root_b)->chunk = partition;
}

void		quick_sort(t_stack **root_a, t_stack **root_b, int size)
{
	int pivot;
	int chunk;
	int mid;

	chunk = 0;
	mid = calc_mid(*root_a);
	while (!is_empty(*root_a) && size > 3)
	{
		chunk += 1;
		pivot = (mid) ? mid : (*root_a)->data;
		mid ? (*root_a)->med = 1 : 0;
		move_partitions(root_a, root_b, pivot, &size, chunk);
		mid = 0;
	}
	if (size == 3)
		sort_three(root_a);
	else if (size == 2)
		((*root_a)->data > (*root_a)->next->data) ? swap(root_a) : 0;
	while (!is_empty(*root_b))
		move_b(root_a, root_b);
}