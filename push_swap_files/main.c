/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:14:05 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/10 15:25:01 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int arg, char **argc)
{
	t_stack_a	*root_a;
	t_stack_a	*current;

	root_a = NULL;
	error_check(arg, argc);
	while (--arg > 0)
		push(&root_a, ft_atoi(argc[arg]));
	error_doubles(root_a);
	current = root_a;
	while (current)
	{
		ft_printf("result %d\n", current->data);
		current = current->next;
	}
	return (0);
}
