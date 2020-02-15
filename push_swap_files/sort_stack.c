/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:24:07 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/15 19:44:34 by vkurkela         ###   ########.fr       */
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

void	sort_stack_test(t_stack **root_a, t_stack **root_b)
{
	int tmp = (*root_a)->data; 
	push_ab(root_a, root_b);
	ft_printf("pb\n");
	while (!is_empty(*root_a)) 
    {
		tmp = (*root_a)->data;
        if (tmp > (*root_b)->data)
		{
            push_ab(root_a, root_b);
			ft_printf("pb\n");
		}
		else
		{
			rotate(root_a);
			ft_printf("ra\n");
			while ((*root_b) && tmp < (*root_b)->data)
			{
				push_ab(root_b, root_a);
				ft_printf("pa\n");
			}
			reverse_rotate(root_a);
			push_ab(root_a, root_b);
			ft_printf("rra\n");
			ft_printf("pb\n");
		}
    }
	while (!is_empty(*root_b))
	{
		push_ab(root_b, root_a);
		ft_printf("pa\n");
	}
}

void	sort_stack(t_stack **root_a, t_stack **root_b)
{
	t_stack *current;
	int		size;
	int		mid;

	current = *root_a;
	size = 0;
	mid = 0;
	while (current)
	{
		mid += current->data;
		current = current->next;
		size++;
	}
	mid /= size;
	if (size == 2 && (*root_a)->data > (*root_a)->next->data)
		rotate(root_a);
	else if (size == 3)
		sort_stack_3(root_a);
	else
		sort_stack_test(root_a, root_b);
}
