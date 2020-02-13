/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 10:26:04 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/13 16:32:09 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(int arg, char **argc)
{
	t_stack	*root_a;
	t_stack	*root_b;
	char	*rules[MAX];
	//int i = 0;

	root_a = NULL;
	root_b = NULL;
	error_check(arg, argc);
	while (--arg)
		push(&root_a, ft_atoi(argc[arg]));
	error_doubles(root_a);
	if (!(read_instructions(rules)))
		return (0);
	execute_rules(&root_a, &root_b, rules);
	/*
	while (rules[i])
	{
		ft_printf("rule %d: %s\n",i , rules[i]);
		i++;
	}
	*/
	print_stack(root_a);
    return (0);
}