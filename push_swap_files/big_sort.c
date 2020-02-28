/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 21:56:19 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/28 20:03:04 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	move_b(t_stack **root_a, t_stack **root_b, int *tab, int *size)
{
	int way;

	way = shortest_way(*root_b, tab[*size]);
	while ((*root_b)->data != tab[*size])
	{
		if ((*root_b)->next)
		{
			if ((*root_b)->next->data == tab[*size])
			{
				swap(root_b);
				break ;
			}
		}
		if (way < 0)
			reverse_rotate(root_b);
		else
			rotate(root_b);
	}
	*size -= 1;
	push_ab(root_b, root_a);
}

static void	move_partitions(t_stack **root_a, t_stack **root_b,\
		int pivot, int pos)
{
	int round;

	round = (*root_a)->data;
	pos = pivot - pos;
	rotate(root_a);
	while ((*root_a)->data != round && pos > 0)
	{
		if ((*root_a)->data <= pivot)
		{
			push_ab(root_a, root_b);
			pos--;
		}
		else
			rotate(root_a);
	}
	if ((*root_a)->data <= pivot)
		push_ab(root_a, root_b);
}

void		big_sort(t_stack **root_a, t_stack **root_b, int size)
{
	int mid;
	int	*tab;
	int len;
	int round;
	int pos;

	mid = 0;
	pos = 0;
	tab = sort_tab(*root_a, size);
	len = size - 1;
	round = (size <= 100) ? 2 : 1;
	while (!is_empty(*root_a) && round <= 10)
	{
		mid = (round == 10) ? tab[len] : tab[(size / 10) * round];
		move_partitions(root_a, root_b, mid, pos);
		pos = mid;
		round = (size <= 100) ? round + 2 : round + 1;
	}
	while (!is_empty(*root_b))
		move_b(root_a, root_b, tab, &len);
	free(tab);
}
