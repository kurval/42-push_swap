/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:25:05 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/25 10:42:59 by vkurkela         ###   ########.fr       */
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

int		is_empty(t_stack *root)
{
	return (!root);
}

t_stack	*new_node(int data, char c, int s)
{
	t_stack *new_node;

	new_node = (t_stack*)malloc(sizeof(t_stack));
	new_node->data = data;
	new_node->stack = c;
	new_node->both = 0;
	new_node->sort = s;
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

void	push(t_stack **root, int data, char c, int s)
{
	t_stack	*node;

	node = new_node(data, c, s);
	node->next = *root;
	*root = node;
}
