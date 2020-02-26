/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:01:45 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/26 23:05:06 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	print_stack(t_stack *root_a, t_stack *root_b)
{
	t_stack *current_a;
	t_stack *current_b;
	char	top[4];

	current_a = root_a;
	current_b = root_b;
	ft_strcpy(top, "TOP");
	ft_printf(BOLDYELLOW "%-*c" RESET, 4, 'A');
	ft_printf(BOLDWHITE "%s" RESET, top);
	ft_printf(BOLDMAGENTA "%*c\n" RESET, 4, 'B');
	while (current_a || current_b)
	{
		if (current_a)
		{
			ft_printf(BOLDWHITE "%-*d" RESET, 10, current_a->data);
			current_a = current_a->next;
		}
		if (current_b)
		{
			ft_printf(BOLDWHITE "%d" RESET, current_b->data);
			current_b = current_b->next;
		}
		ft_printf("\n");
	}
}
