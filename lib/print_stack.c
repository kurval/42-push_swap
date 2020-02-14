/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:01:45 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/14 10:26:37 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	print_stack(t_stack *root)
{
	t_stack *current;

	current = root;
	while (current)
	{
		ft_printf("%d\n", current->data);
		current = current->next;
	}
}
