/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 10:44:43 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/16 13:20:40 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	print_swap(t_stack *root)
{
	if (root->stack == '-' || !root->stack)
		return ;
	if (!root->both)
		root->stack == 'a' ? write(1, "sa\n", 3) :\
		write(1, "sb\n", 3);
	else
	{
        root->both == 1 ? write(1, "ss\n", 3) : 0;
        root->both = 0;
    }
}

void	swap(t_stack **root)
{
	int temp;

	if (is_empty(*root) || is_empty((*root)->next))
		return ;
	print_swap(*root);
	temp = (*root)->data;
	(*root)->data = (*root)->next->data;
	(*root)->next->data = temp;
}

void	swap_both(t_stack **root_a, t_stack **root_b)
{
	(*root_a)->both = 1;
	(*root_b)->both = 2;
	swap(root_a);
	swap(root_b);
}