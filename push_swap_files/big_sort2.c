/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 21:56:19 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/22 14:58:46 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	move_a(t_stack **root_a, t_stack **root_b, int *tab, int *size, int mid)
{
	int len = *size;
	int med = mid/2;
	while (len >= 0)
	{
		reverse_rotate(root_a);
		if ((*root_a)->data != tab[*size])
		{
			push_ab(root_a, root_b);
			if ((*root_b)->data < med)
				rotate(root_b);
		}
		else
			*size -= 1;
		len--;
	}
}

static void	move_b(t_stack **root_a, t_stack **root_b, int *tab, int *size)
{
	int way;
	int len;

	if (*size < 0)
		len = -*size;
	else
		len = *size;
	way = shortest_way(*root_b, tab[len]);
	while ((*root_b)->data != tab[len])
	{
		if (way < 0	)
			reverse_rotate(root_b);
		else
			rotate(root_b);
	}
	*size -= 1;
	push_ab(root_b, root_a);
	(*root_a)->sort = 1;
}

static void	move_partitions(t_stack **root_a, t_stack **root_b,\
		int pivot)
{
	int round;
	
	round = (*root_a)->data;
	rotate(root_a);
	while ((*root_a)->data != round)
	{
		if ((*root_a)->data > pivot)
			push_ab(root_a, root_b);
		else
			rotate(root_a);
	}
	if ((*root_a)->data > pivot)
		push_ab(root_a, root_b);
}

void		big_sort(t_stack **root_a, t_stack **root_b, int size)
{
	int mid;
	int	*tab;
	int len;
	int i;

	mid = 0;
	tab = calc_med(*root_a, size, &mid);
	len = size -1;
	i = 0;
	move_partitions(root_a, root_b, mid);
	while (!is_empty(*root_b))
		move_b(root_a, root_b, tab, &len);
	move_a(root_a, root_b, tab, &len, mid);
	while (!is_empty(*root_b))
		move_b(root_a, root_b, tab, &len);
}