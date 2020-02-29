/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:18:12 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/28 21:09:51 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static void	print_push(t_stack *root)
{
	if (root->stack == '-')
		return ;
	root->stack == 'a' ? write(1, "pb\n", 3) :\
	write(1, "pa\n", 3);
}

void		push_ab(t_stack **root, t_stack **stack)
{
	t_stack *temp;
	char	c;
	int		s;

	if (is_empty(*root))
		return ;
	print_push(*root);
	if ((*root)->stack == 'a' || (*root)->stack == 'b')
		c = (*root)->stack == 'a' ? 'b' : 'a';
	else
		c = '-';
	s = (*root)->flag ? 1 : 0;
	temp = *root;
	*root = (*root)->next;
	push(stack, temp->data, c, s);
	free(temp);
}
