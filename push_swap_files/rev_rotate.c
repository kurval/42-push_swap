/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 11:51:07 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/16 11:51:39 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	print_rev_rotate(t_stack *root)
{
	if (!root->both)
		root->stack == 'a' ? write(1, "rra\n", 4) :\
		write(1, "rrb\n", 4);
	else
    {
        root->both == 1 ? write(1, "rrr\n", 4) : 0;
        root->both = 0;
    }
}

void	reverse_rotate(t_stack **root)
{
	t_stack *second_last;
	char	c;

	if (is_empty(*root) || is_empty((*root)->next))
		return ;
    print_rev_rotate(*root);
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