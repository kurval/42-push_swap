/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:18:12 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/11 21:13:12 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void push_b(t_stack **root_a, t_stack **root_b) 
{ 
    if (isEmpty(*root_a)) 
        return ; 
    t_stack *temp = *root_a; 
    *root_a = (*root_a)->next;
    push(root_b, temp->data);
    free(temp);
}

void push_a(t_stack **root_b, t_stack **root_a)
{ 
    if (isEmpty(*root_b)) 
        return ; 
    t_stack *temp = *root_b; 
    *root_b = (*root_b)->next;
    push(root_a, temp->data);
    free(temp);
}

void swap_a(t_stack **root_a)
{
    int temp;
    
    if (isEmpty(*root_a) || isEmpty((*root_a)->next))
        return ;
    temp = (*root_a)->data;
    (*root_a)->data = (*root_a)->next->data;
    (*root_a)->next->data = temp;
}

void swap_b(t_stack **root_b)
{
    int temp;
    
    if (isEmpty(*root_b) || isEmpty((*root_b)->next))
        return ;
    temp = (*root_b)->data;
    (*root_b)->data = (*root_b)->next->data;
    (*root_b)->next->data = temp;
}

void rotate_a(t_stack **root_a)
{
    t_stack *second_last = *root_a;
    while (second_last->next->next != NULL)
        second_last = second_last->next;
    push(root_a, second_last->next->data);
    del_node(&second_last->next);
}