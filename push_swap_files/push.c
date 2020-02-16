/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:18:12 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/16 10:45:38 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_ab(t_stack **root, t_stack **stack)
{
	t_stack *temp;
	char c;

	if (is_empty(*root))
		return ;
	(*root)->stack == 'a' ? write(1, "pb\n", 3) :\
	write(1, "pa\n", 3);
	c = (*root)->stack == 'a' ? 'b' : 'a';
	temp = *root;
	*root = (*root)->next;
	push(stack, temp->data, c);
	free(temp);
}
