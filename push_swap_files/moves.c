/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:18:12 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/12 11:28:21 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void push_ab(t_stack **root, t_stack **stack) 
{
    t_stack *temp = NULL;
    
    if (is_empty(*root)) 
        return ; 
    temp = *root;
    *root = (*root)->next;
    push(stack, temp->data);
    free(temp);
}

void swap(t_stack **root)
{
    int temp;
    
    if (is_empty(*root) || is_empty((*root)->next))
        return ;
    temp = (*root)->data;
    (*root)->data = (*root)->next->data;
    (*root)->next->data = temp;
}

void rotate(t_stack **root)
{   
    int first = (*root)->data;
    t_stack *last = new_node(first);
    t_stack *temp = *root;

    *root = (*root)->next;
    free(temp);
    temp = *root;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = last;
}

void reverse_rotate(t_stack **root)
{
    t_stack *second_last = *root;
    
    while (second_last->next->next != NULL)
        second_last = second_last->next;
    push(root, second_last->next->data);
    del_node(&second_last->next);
}