/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:01:29 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/15 20:08:29 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	push(t_stack **root, int data, char c)
{
	t_stack	*node;

	node = new_node(data, c);
	node->next = *root;
	node->stack = c;
	*root = node;
}
