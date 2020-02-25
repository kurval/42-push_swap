/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:14:05 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/25 10:16:57 by vkurkela         ###   ########.fr       */
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
		push(&root_a, ft_atoi(argc[arg]), 'a', 0);
	error_doubles(root_a);
	sort_stack(&root_a, &root_b);
	free_stack(root_a);
	return (0);
}
