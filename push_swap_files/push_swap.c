/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:14:05 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/14 14:13:42 by vkurkela         ###   ########.fr       */
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
	{
		push(&root_a, ft_atoi(argc[arg]));
		root_a->stack = 'a';
	}
	error_doubles(root_a);

	//ft_printf("stack a:\n");
	//print_stack(root_a);

	sort_stack(&root_a, &root_b);
	//ft_printf("2 round:\n");
	//ft_printf("stack b:\n");
	//print_stack(root_b);

	//ft_printf("stack a:\n");
	//print_stack(root_a);
	free_stack(root_a);
	return (0);
}
