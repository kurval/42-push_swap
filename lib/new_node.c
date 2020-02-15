/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:01:51 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/15 20:26:11 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_stack	*new_node(int data, char c)
{
	t_stack *new_node;

	new_node = (t_stack*)malloc(sizeof(t_stack));
	new_node->data = data;
	new_node->next = NULL;
	new_node->stack = c;
	return (new_node);
}