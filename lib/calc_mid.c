/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_mid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:20:57 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/19 15:23:07 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		calc_mid(t_stack **root_a)
{
    t_stack *current;
	int		size;
	int		mid;

	current = *root_a;
	size = 0;
	mid = (*root_a)->data;
	while (current)
	{
		mid += current->data;
		current = current->next;
		size++;
	}
	mid /= size;
    return (mid);
}