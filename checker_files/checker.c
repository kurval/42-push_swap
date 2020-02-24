/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 10:26:04 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/24 11:33:58 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(int arg, char **argc)
{
	t_stack	*root_a;
	t_stack	*root_b;
	t_rules	*rules_lst;
	//int i = 0;

	root_a = NULL;
	root_b = NULL;
	error_check(arg, argc);
	while (--arg)
		push(&root_a, ft_atoi(argc[arg]), '-', 0);
	error_doubles(root_a);
	if (!read_instructions(&rules_lst) || !check_rules(rules_lst))
	{
		free_rules(rules_lst);
		free_stack(root_a);
		ft_printf(BOLDRED "Error\n" RESET);
		return (0);
	}
	execute_rules(&root_a, &root_b, rules_lst);
	check_order(root_a, root_b) ? ft_printf(BOLDGREEN "OK\n" RESET) :\
	ft_printf(BOLDRED "KO\n" RESET);
	/*
	while (rules[i])
	{
		ft_printf("rule %d: %s\n",i , rules[i]);
		i++;
	}
	*/
	//print_stack(root_a);
	free_stack(root_a);
	return (0);
}
