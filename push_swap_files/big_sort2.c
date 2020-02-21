/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 21:56:19 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/21 13:45:53 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	move_b(t_stack **root_a, t_stack **root_b, int *tab)
{
	int tmp;

	ft_printf("shortest way for %d on %d\n", tab[9], shortest_way(*root_b, tab[9]));
	tmp = (*root_b)->data;
	push_ab(root_b, root_a);
	(*root_a)->sort = 1;
	while (!is_empty(*root_b))
	{
		tmp = (*root_b)->data;
		if (tmp < (*root_a)->data && (*root_a)->sort)
		{
			push_ab(root_b, root_a);
			(*root_a)->sort = 1;
		}
		else
		{
			rotate(root_b);
			while ((*root_a)->sort && tmp > (*root_a)->data)
				push_ab(root_a, root_b);
			reverse_rotate(root_b);
			push_ab(root_b, root_a);
			(*root_a)->sort = 1;
		}
	}
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

	i = 0;
	mid = 0;
	tab = calc_med(*root_a, size, &mid);
	move_partitions(root_a, root_b, mid);

	ft_printf("b on: \n");
	print_stack(*root_b);
	move_b(root_a, root_b, tab);
	
	while (i < size)
	{
		ft_printf("%d", tab[i]);
		i++;
	}
	ft_printf("\n");
}