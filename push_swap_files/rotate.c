/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 10:43:33 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/16 11:17:39 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack **root)
{
	int		first;
	char	c;
	t_stack *last;
	t_stack *temp;

	if (is_empty(*root) || is_empty((*root)->next))
		return ;
	if (!(*root)->both)
		(*root)->stack == 'a' ? write(1, "ra\n", 3) :\
		write(1, "rb\n", 3);
	else if ((*root)->both == 1)
        write(1, "rr\n", 3);
	c = (*root)->stack == 'a' ? 'a' : 'b';
	first = (*root)->data;
	last = new_node(first, c);
	temp = *root;
	*root = (*root)->next;
	free(temp);
	temp = *root;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = last;
}

void	rotate_both(t_stack **root_a, t_stack **root_b)
{
	(*root_a)->both = 1;
	(*root_b)->both = 2;
	rotate(root_a);
	rotate(root_b);
}

void	reverse_rotate(t_stack **root)
{
	t_stack *second_last;
	char	c;

	if (is_empty(*root) || is_empty((*root)->next))
		return ;
	if (!(*root)->both)
		(*root)->stack == 'a' ? write(1, "rra\n", 4) :\
		write(1, "rrb\n", 4);
	else
    {
        (*root)->both == 1 ? write(1, "rrr\n", 4) : 0;
        (*root)->both = 0;
    }
	c = (*root)->stack == 'a' ? 'a' : 'b';
	second_last = *root;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	push(root, second_last->next->data, c);
	del_node(&second_last->next);
}

void	rev_rotate_both(t_stack **root_a, t_stack **root_b)
{
	(*root_a)->both = 1;
	(*root_b)->both = 2;
	reverse_rotate(root_a);
	reverse_rotate(root_b);
}