/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 10:43:33 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/28 21:03:12 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static void	print_rotate(t_stack *root)
{
	if (root->stack == '-')
		return ;
	if (!root->both)
	{
		root->stack == 'a' ? write(1, "ra\n", 3) :\
		write(1, "rb\n", 3);
	}
	else if (root->both == 1)
		write(1, "rr\n", 3);
}

void		rotate(t_stack **root)
{
	int		first;
	char	c;
	int		s;
	t_stack *last;
	t_stack *temp;

	if (is_empty(*root) || is_empty((*root)->next))
		return ;
	print_rotate(*root);
	if ((*root)->stack == 'a' || (*root)->stack == 'b')
		c = (*root)->stack == 'a' ? 'a' : 'b';
	else
		c = '-';
	s = (*root)->flag ? 1 : 0;
	first = (*root)->data;
	last = new_node(first, c, s);
	temp = *root;
	*root = (*root)->next;
	free(temp);
	temp = *root;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = last;
}

void		rotate_both(t_stack **root_a, t_stack **root_b)
{
	if (is_empty(*root_a) || is_empty((*root_a)->next) ||\
			is_empty(*root_b) || is_empty((*root_b)->next))
		return ;
	(*root_a)->both = 1;
	(*root_b)->both = 2;
	rotate(root_a);
	rotate(root_b);
}
