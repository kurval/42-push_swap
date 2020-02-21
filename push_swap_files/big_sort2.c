/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 21:56:19 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/21 15:48:03 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	move_b(t_stack **root_a, t_stack **root_b, int *tab, int *size)
{
	int way;

	way = shortest_way(*root_b, tab[*size - 1]);
	while ((*root_b)->data != tab[*size - 1])
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
		{
			push_ab(root_a, root_b);
		}
		else
			rotate(root_a);
	}
}

void		big_sort(t_stack **root_a, t_stack **root_b, int size)
{
	int mid;
	int	*tab;
	int i;
	int len;

	i = 0;
	mid = 0;
	tab = calc_med(*root_a, size, &mid);
	len = size;
	move_partitions(root_a, root_b, mid);

	ft_printf("b on: \n");
	print_stack(*root_b);
	while (!is_empty(*root_b))
		move_b(root_a, root_b, tab, &len);
	while (i < size)
	{
		ft_printf("%d", tab[i]);
		i++;
	}
	ft_printf("a on: \n");
	print_stack(*root_a);
}