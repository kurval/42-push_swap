/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 21:56:19 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/18 12:05:07 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void move_partitions(t_stack **root_a, t_stack **root_b, int pivot, int *size, int partition)
{
    rotate(root_a);
	while ((*root_a)->data != pivot)
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
    push_ab(root_a, root_b);
    (*root_b)->chunk = partition;
}

void	quick_sort(t_stack **root_a, t_stack **root_b, int size)
{
	int pivot;
    int chunk;

    chunk = 0;
    while (size > 3)
    {
        pivot = (*root_a)->data;
        chunk += 1;
        move_partitions(root_a, root_b, pivot, &size, chunk);
        //ft_printf("size on %d\n", size);
        ft_printf("pivot on %d\n", pivot);
    }
}