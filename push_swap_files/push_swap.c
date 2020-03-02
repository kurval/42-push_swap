/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:14:05 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/02 11:45:11 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int arg, char **argc)
{
	t_stack	*root_a;
	t_stack	*root_b;
	char	**tab;
	int		size;

	root_a = NULL;
	root_b = NULL;
	tab = (arg == 2) ? ft_strsplit(argc[1], ' ') : NULL;
	size = (arg == 2) ? ft_tab_size(tab) : 0;
	(arg == 2) ? error_check(size, tab, 1) :\
	error_check(arg, argc, 0);
	(arg == 2) ? push_args(size, tab, &root_a, 'a') :\
	push_args(arg, argc, &root_a, 'a');
	(arg == 2) ? free_tab(tab) : 0;
	error_doubles(root_a);
	sort_stack(&root_a, &root_b);
	return (0);
}
