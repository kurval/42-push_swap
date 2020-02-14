/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:01:29 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/14 10:26:50 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	push(t_stack **root, int data)
{
	t_stack	*node;

	node = new_node(data);
	node->next = *root;
	*root = node;
}
