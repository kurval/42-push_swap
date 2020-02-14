/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:24:07 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/14 10:37:44 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack_3(t_stack **root_a)
{
	if ((*root_a)->data < (*root_a)->next->data &&\
			(*root_a)->next->next->data > (*root_a)->data &&\
			(*root_a)->next->data > (*root_a)->next->next->data)
	{
		swap(root_a);
		rotate(root_a);
	}
	else if ((*root_a)->data > (*root_a)->next->data &&\
			(*root_a)->next->next->data < (*root_a)->data &&\
			(*root_a)->next->data > (*root_a)->next->next->data)
	{
		rotate(root_a);
		swap(root_a);
	}
	else if ((*root_a)->data < (*root_a)->next->data &&\
			(*root_a)->next->next->data < (*root_a)->next->data)
		reverse_rotate(root_a);
	else if ((*root_a)->data > (*root_a)->next->next->data &&\
			(*root_a)->data > (*root_a)->next->data)
		rotate(root_a);
	else if ((*root_a)->data > (*root_a)->next->data &&\
			(*root_a)->data < (*root_a)->next->next->data)
		swap(root_a);
}

void	sort_stack(t_stack **root_a, t_stack **root_b)
{
	t_stack *current;
	int		size;

	current = *root_a;
	size = 0;
	while (current)
	{
		current = current->next;
		size++;
	}
	if (size == 2 && (*root_a)->data > (*root_a)->next->data)
		rotate(root_a);
	else if (size == 3)
		sort_stack_3(root_a);
	*root_b = NULL;
}
