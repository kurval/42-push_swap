/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 21:56:19 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/18 18:08:07 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void sort_b(t_stack **root_a, t_stack **root_b, int pivot)
{
    while ((*root_b)->tag)
        push_ab(root_b, root_a);
    pivot = (*root_b)->data;
    rotate(root_b);
    ft_printf("pivot on %d\n", pivot);
    while ((*root_b)->data != pivot)
	{
		if ((*root_b)->data > pivot)
        {
            if (is_empty(*root_a))
                push_ab(root_b, root_a);
			else if ((*root_a)->data > (*root_b)->data)
            {
                ft_printf("pushataan %d\n", (*root_b)->data);
                push_ab(root_b, root_a);
            }
            else
            {
                rotate(root_a);
                push_ab(root_b, root_a);
                reverse_rotate(root_a);
            }
        }
		else
			rotate(root_b);
	}
    push_ab(root_b, root_a);
}

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
    (*root_b)->tag = 1;
    (*root_b)->chunk = partition;
}

void	quick_sort(t_stack **root_a, t_stack **root_b, int size)
{
	int pivot;
    int chunk;

    chunk = 0;
    while (!is_empty(*root_a) || size <= 3)
    {
        pivot = (*root_a)->data;
        chunk += 1;
        move_partitions(root_a, root_b, pivot, &size, chunk);
    }
    while (!is_empty(*root_b))
    {
        pivot = 0;
        sort_b(root_a, root_b, pivot);
    }
}