/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:18:12 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/12 16:35:03 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void push_ab(t_stack **root, t_stack **stack, char c) 
{
    t_stack *temp = NULL;
    
    if (is_empty(*root)) 
        return ; 
    temp = *root;
    *root = (*root)->next;
    push(stack, temp->data);
    c == 'a' ? write(1, "pa\n", 3) : write(1, "pa\n", 3);
    free(temp);
}

void swap(t_stack **root, char c)
{
    int temp;
    
    if (is_empty(*root) || is_empty((*root)->next))
        return ;
    temp = (*root)->data;
    (*root)->data = (*root)->next->data;
    (*root)->next->data = temp;
    c == 'a' ? write(1, "sa\n", 3) : write(1, "sb\n", 3);
}

void rotate(t_stack **root, char c)
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
    c == 'a' ? write(1, "ra\n", 3) : write(1, "rb\n", 3);
}

void reverse_rotate(t_stack **root, char c)
{
    t_stack *second_last = *root;
    
    while (second_last->next->next != NULL)
        second_last = second_last->next;
    push(root, second_last->next->data);
    del_node(&second_last->next);
    c == 'a' ? write(1, "rra\n", 4) : write(1, "rrb\n", 4);
}