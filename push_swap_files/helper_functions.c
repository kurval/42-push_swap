/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:24:05 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/11 21:09:21 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int isEmpty(t_stack *root) 
{ 
    return !root;
}

void	del_node(t_stack **node)
{
	if (node != NULL && *node != NULL)
	{
		free(*node);
		*node = NULL;
	}
}

t_stack *new_node(int data)
{ 
    t_stack *new_node;
	
	new_node = (t_stack*)malloc(sizeof(t_stack)); 
    new_node->data = data; 
    new_node->next = NULL; 
    return new_node; 
}

void push(t_stack **root, int data) 
{ 
	t_stack	*node;

    node = new_node(data);
    node->next = *root;
    *root = node;
}