/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:17:50 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/12 12:33:22 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    sort_stack_3(t_stack **root_a, t_stack **root_b)
{
     if ((*root_a)->data < (*root_a)->next->data &&\
        (*root_a)->next->next->data > (*root_a)->data &&\
        (*root_a)->next->data > (*root_a)->next->next->data)
    {
        swap(root_a);
        rotate(root_a);
    }
    else if ((*root_a)->data > (*root_a)->next->data &&\
        (*root_a)->next->next->data < (*root_a)->data &&\
        (*root_a)->next->data > (*root_a)->next->next->data)
    {
        rotate(root_a);
        swap(root_a);
    }
    else if ((*root_a)->data < (*root_a)->next->data &&\
        (*root_a)->next->next->data < (*root_a)->next->data)
        reverse_rotate(root_a);
    else if ((*root_a)->data > (*root_a)->next->next->data &&\
        (*root_a)->data > (*root_a)->next->data)
        rotate(root_a);
    else if ((*root_a)->data > (*root_a)->next->data &&\
        (*root_a)->data < (*root_a)->next->next->data)
        swap(root_a);
    *root_b = NULL;
}

void    sort_stack(t_stack **root_a, t_stack **root_b)
{
    t_stack *current = *root_a;
    int size = 0;

    while (current)
    {
        current = current->next;
        size++;
    }
    if (size == 3)
        sort_stack_3(root_a, root_b);
}