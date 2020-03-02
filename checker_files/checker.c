/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 10:26:04 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/02 11:35:18 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	get_rules(t_rules **rules_lst, t_stack *root_a)
{
	if (!read_instructions(rules_lst) || !check_rules(*rules_lst))
	{
		free_rules(*rules_lst);
		free_stack(root_a);
		ft_printf(BOLDRED "Error\n" RESET);
		exit(0);
	}
}

int			main(int arg, char **argc)
{
	t_stack	*root_a;
	t_stack	*root_b;
	t_rules	*rules_lst;
	char	**tab;
	int		size;

	root_a = NULL;
	root_b = NULL;
	tab = (arg == 2) ? ft_strsplit(argc[1], ' ') : NULL;
	size = (arg == 2) ? ft_tab_size(tab) : 0;
	(arg == 2) ? error_check(size, tab, 1) :\
	error_check(arg, argc, 0);
	(arg == 2) ? push_args(size, tab, &root_a, '-') :\
	push_args(arg, argc, &root_a, '-');
	error_doubles(root_a);
	get_rules(&rules_lst, root_a);
	execute_rules(&root_a, &root_b, rules_lst);
	check_order(root_a, root_b) ? ft_printf(BOLDGREEN "OK\n" RESET) :\
	ft_printf(BOLDRED "KO\n" RESET);
	free_stack(root_a);
	(arg == 2) ? free_tab(tab) : 0;
	return (0);
}
