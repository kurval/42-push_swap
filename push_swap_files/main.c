/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:14:05 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/11 20:12:50 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int arg, char **argc)
{
	t_stack	*root_a;
	t_stack	*root_b;
	t_stack	*current_a;
	t_stack	*current_b;

	root_a = NULL;
	root_b = NULL;
	error_check(arg, argc);
	while (--arg > 0)
		push(&root_a, ft_atoi(argc[arg]));
	error_doubles(root_a);
	//push_b(&root_a, &root_b);
	//push_a(&root_b, &root_a);
	current_a = root_a;
	while (current_a)
	{
		ft_printf("stack a %d\n", current_a->data);
		current_a = current_a->next;
	}
	current_b = root_b;
	ft_printf("2 round:\n");
	while (current_b)
	{
		ft_printf("stack b %d\n", current_b->data);
		current_b = current_b->next;
	}
	//swap_a(&root_a);
	rotate_a(&root_a);
	current_a = root_a;
	while (current_a)
	{
		ft_printf("stack a %d\n", current_a->data);
		current_a = current_a->next;
	}
	return (0);
}
