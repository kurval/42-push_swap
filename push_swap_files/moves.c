/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:18:12 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/15 17:07:26 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_ab(t_stack **root, t_stack **stack)
{
	t_stack *temp;

	if (is_empty(*root))
		return ;
	(*root)->stack == 'a' ? write(1, "pa\n", 3) :\
	write(1, "pb\n", 3);
	temp = *root;
	*root = (*root)->next;
	push(stack, temp->data);
	free(temp);
}

void	swap(t_stack **root)
{
	int temp;

	if (is_empty(*root) || is_empty((*root)->next))
		return ;
	(*root)->stack == 'a' ? write(1, "sa\n", 3) :\
	write(1, "sb\n", 3);
	temp = (*root)->data;
	(*root)->data = (*root)->next->data;
	(*root)->next->data = temp;
}

void	rotate(t_stack **root)
{
	int		first;
	t_stack *last;
	t_stack *temp;

	if (is_empty(*root) || is_empty((*root)->next))
		return ;
	(*root)->stack == 'a' ? write(1, "ra\n", 3) :\
	write(1, "rb\n", 3);
	first = (*root)->data;
	last = new_node(first);
	temp = *root;
	*root = (*root)->next;
	free(temp);
	temp = *root;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = last;
}

void	reverse_rotate(t_stack **root)
{
	t_stack *second_last;

	if (is_empty(*root) || is_empty((*root)->next))
		return ;
	(*root)->stack == 'a' ? write(1, "rra\n", 4) :\
	write(1, "rrb\n", 4);
	second_last = *root;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	push(root, second_last->next->data);
	del_node(&second_last->next);
}
