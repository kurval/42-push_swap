/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:24:05 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/10 15:26:24 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_a* newNode(int data) 
{ 
    t_stack_a *stackNode;
	
	stackNode = (t_stack_a*)malloc(sizeof(t_stack_a)); 
    stackNode->data = data; 
    stackNode->next = NULL; 
    return stackNode; 
}

void push(t_stack_a **root, int data) 
{ 
	t_stack_a	*new_node;

    new_node = newNode(data);
    new_node->next = *root;
    *root = new_node;
} 