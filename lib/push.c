/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:18:12 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/16 13:25:58 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	print_push(t_stack *root)
{
	if (root->stack == '-' || !root->stack)
		return ;
	root->stack == 'a' ? write(1, "pb\n", 3) :\
	write(1, "pa\n", 3);
}

void	push_ab(t_stack **root, t_stack **stack)
{
	t_stack *temp;
	char c;

	if (is_empty(*root))
		return ;
	print_push(*root);
	if ((*root)->stack == 'a' || (*root)->stack == 'b')
		c = (*root)->stack == 'a' ? 'b' : 'a';
	else
		c = (*root)->stack == '-';
	temp = *root;
	*root = (*root)->next;
	push(stack, temp->data, c);
	free(temp);
}
