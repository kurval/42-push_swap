/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:01:45 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/29 08:48:36 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void		print_start(t_stack *root_a, t_stack *root_b)
{
	if ((root_a))
	{
		if ((root_a)->flag)
		{
			ft_printf(BOLDGREEN "START\n" RESET);
			print_stack(root_a, root_b);
		}
	}
}

void		print_steps(t_stack *root_a, t_stack *root_b, char *step)
{
	if (root_a)
	{
		if ((root_a)->flag)
		{
			ft_printf(BOLDGREEN "=>" RESET);
			ft_printf(BOLDBLUE "%s\n" RESET, step);
			print_stack(root_a, root_b);
		}
	}
	else if (root_b)
	{
		if ((root_b)->flag)
		{
			ft_printf(BOLDGREEN "=>" RESET);
			ft_printf(BOLDBLUE "%s\n" RESET, step);
			print_stack(root_a, root_b);
		}
	}
}

static void	print_numbers(t_stack *current_a, t_stack *current_b)
{
	if (current_a)
		ft_printf(BOLDWHITE "%-*d" RESET, 10, current_a->data);
	else
		ft_printf(BOLDWHITE "%-*c" RESET, 10, ' ');
	if (current_b)
		ft_printf(BOLDRED "%d" RESET, current_b->data);
	ft_printf("\n");
}

void		print_stack(t_stack *root_a, t_stack *root_b)
{
	t_stack *current_a;
	t_stack *current_b;
	char	top[4];

	current_a = root_a;
	current_b = root_b;
	ft_strcpy(top, "TOP");
	ft_printf(BOLDYELLOW "%-*c" RESET, 4, 'A');
	ft_printf(BOLDWHITE "%s" RESET, top);
	ft_printf(BOLDYELLOW "%*c\n" RESET, 4, 'B');
	while (current_a || current_b)
	{
		print_numbers(current_a, current_b);
		if (current_a)
			current_a = current_a->next;
		if (current_b)
			current_b = current_b->next;
	}
}
