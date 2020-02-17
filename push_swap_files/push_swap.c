/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:14:05 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/17 18:21:49 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int arg, char **argc)
{
	t_stack	*root_a;
	t_stack	*root_b;

	root_a = NULL;
	root_b = NULL;
	error_check(arg, argc);
	while (--arg)
		push(&root_a, ft_atoi(argc[arg]), 'a');
	error_doubles(root_a);


	sort_stack(&root_a, &root_b);
	//ft_printf("2 round:\n");
	/*
	ft_printf("stack a:\n");
	print_stack(root_a);

	ft_printf("stack b:\n");
	print_stack(root_b);
	*/
	//print_stack(root_a);

	free_stack(root_a);
	return (0);
}
