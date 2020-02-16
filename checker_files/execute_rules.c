/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_rules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:18:37 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/16 17:15:13 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	check_rr(t_stack **root_a, t_stack **root_b, char **rules, int *i)
{
	!ft_strncmp_end(rules[*i], "rra", 3) ? reverse_rotate(root_a) : 0;
	!ft_strncmp_end(rules[*i], "rrb", 3) ? reverse_rotate(root_b) : 0;
	!ft_strncmp_end(rules[*i], "rrr", 3) ? rev_rotate_both(root_a, root_b) : 0;
}

static void	check_r(t_stack **root_a, t_stack **root_b, char **rules, int *i)
{
	!ft_strncmp_end(rules[*i], "ra", 2) ? rotate(root_a) : 0;
	!ft_strncmp_end(rules[*i], "rb", 2) ? rotate(root_b) : 0;
	!ft_strncmp_end(rules[*i], "rr", 2) ? rotate_both(root_a, root_b) : 0;
}

static void	check_push(t_stack **root_a, t_stack **root_b, char **rules, int *i)
{
	!ft_strncmp_end(rules[*i], "pa", 2) ? push_ab(root_b, root_a) : 0;
	!ft_strncmp_end(rules[*i], "pb", 2) ? push_ab(root_a, root_b) : 0;
}

static void	check_swap(t_stack **root_a, t_stack **root_b, char **rules, int *i)
{
	!ft_strncmp_end(rules[*i], "sa", 2) ? swap(root_a) : 0;
	!ft_strncmp_end(rules[*i], "sb", 2) ? swap(root_b) : 0;
	!ft_strncmp_end(rules[*i], "ss", 2) ? swap_both(root_a, root_b) : 0;
}

void		execute_rules(t_stack **root_a, t_stack **root_b, char **rules)
{
	int i;

	i = 0;
	while (rules[i])
	{
		check_swap(root_a, root_b, rules, &i);
		check_push(root_a, root_b, rules, &i);
		check_r(root_a, root_b, rules, &i);
		check_rr(root_a, root_b, rules, &i);
		free(rules[i]);
		i++;
	}
}
