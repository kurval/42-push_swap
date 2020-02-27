/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:35:06 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/27 12:01:45 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **root_a)
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
}
