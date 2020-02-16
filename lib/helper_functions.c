/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:25:05 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/16 17:31:26 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	del_node(t_stack **node)
{
	if (node != NULL && *node != NULL)
	{
		free(*node);
		*node = NULL;
	}
}

int	is_empty(t_stack *root)
{
	return (!root);
}

t_stack	*new_node(int data, char c)
{
	t_stack *new_node;

	new_node = (t_stack*)malloc(sizeof(t_stack));
	new_node->data = data;
	new_node->stack = c;
	new_node->next = NULL;
	return (new_node);
}

void	free_stack(t_stack *root)
{
	t_stack *temp;

	temp = NULL;
	if (is_empty(root))
		return ;
	while (root)
	{
		temp = root;
		root = root->next;
		free(temp);
	}
}

void	push(t_stack **root, int data, char c)
{
	t_stack	*node;

	node = new_node(data, c);
	node->next = *root;
	node->stack = c;
	*root = node;
}