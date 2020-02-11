/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:18:12 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/11 10:20:35 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void push_b(t_stack **root_a, t_stack **root_b) 
{ 
    if (isEmpty(*root_a)) 
        return ; 
    t_stack *temp = *root_a; 
    *root_a = (*root_a)->next;
    push(root_b, temp->data);
    free(temp);
}