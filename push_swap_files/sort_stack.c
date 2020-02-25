/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:24:07 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/25 10:31:07 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack_test(t_stack **root_a, t_stack **root_b)
{
	int tmp;

	tmp = (*root_a)->data;
	push_ab(root_a, root_b);
	while (!is_empty(*root_a))
	{
		tmp = (*root_a)->data;
		if (tmp > (*root_b)->data)
			push_ab(root_a, root_b);
		else
		{
			rotate(root_a);
			while ((*root_b) && tmp < (*root_b)->data)
				push_ab(root_b, root_a);
			reverse_rotate(root_a);
			push_ab(root_a, root_b);
		}
	}
	while (!is_empty(*root_b))
		push_ab(root_b, root_a);
}

void	sort_stack(t_stack **root_a, t_stack **root_b)
{
	t_stack *current;
	int		size;
	int		lo;

	current = *root_a;
	size = 0;
	lo = (*root_a)->data;
	while (current)
	{
		lo = current->data < lo ? current->data : lo;
		current = current->next;
		size++;
	}
	if (size == 2 && (*root_a)->data > (*root_a)->next->data)
		rotate(root_a);
	else if (size == 3)
		sort_three(root_a);
	else if (size == 4 || size == 5)
		sort_five(root_a, root_b, lo, size);
	else if (size > 5)
		big_sort(root_a, root_b, size);
}
