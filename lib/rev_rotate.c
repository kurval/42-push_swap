/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 11:51:07 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/02 11:38:36 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static void	print_rev_rotate(t_stack *root)
{
	if (root->stack == '-')
		return ;
	if (!root->both)
		root->stack == 'a' ? write(1, "rra\n", 4) :\
		write(1, "rrb\n", 4);
	else
	{
		root->both == 1 ? write(1, "rrr\n", 4) : 0;
		root->both = 0;
	}
}

void		reverse_rotate(t_stack **root)
{
	t_stack *second_last;
	char	c;
	int		s;

	if (is_empty(*root) || is_empty((*root)->next))
		return ;
	print_rev_rotate(*root);
	if ((*root)->stack == 'a' || (*root)->stack == 'b')
		c = (*root)->stack == 'a' ? 'a' : 'b';
	else
		c = '-';
	second_last = *root;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	s = second_last->next->flag ? 1 : 0;
	push(root, second_last->next->data, c, s);
	del_node(&second_last->next);
}

void		rev_rot_both(t_stack **root_a, t_stack **root_b)
{
	if (is_empty(*root_a) || is_empty((*root_a)->next) ||\
			is_empty(*root_b) || is_empty((*root_b)->next))
		return ;
	(*root_a)->both = 1;
	(*root_b)->both = 2;
	reverse_rotate(root_a);
	reverse_rotate(root_b);
}
