/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_rules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:18:37 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/13 20:46:29 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void check_rr(t_stack **root_a, t_stack **root_b, char **rules, int *i)
{
    !ft_strncmp_end(rules[*i], "rra", 3) ? reverse_rotate(root_a) : 0;
    !ft_strncmp_end(rules[*i], "rrb", 3) ? reverse_rotate(root_b) : 0;
    if (!(ft_strncmp_end(rules[*i], "rrr", 3)))
    {
        reverse_rotate(root_a);
        reverse_rotate(root_b);
    }
}

static void check_rotate(t_stack **root_a, t_stack **root_b, char **rules, int *i)
{
    !ft_strncmp_end(rules[*i], "ra", 2) ? rotate(root_a) : 0;
    !ft_strncmp_end(rules[*i], "rb", 2) ? rotate(root_b) : 0;
    if (!(ft_strncmp_end(rules[*i], "rr", 2)))
    {
        rotate(root_a);
        rotate(root_b);
    }
}

static void check_push(t_stack **root_a, t_stack **root_b, char **rules, int *i)
{
    !ft_strncmp_end(rules[*i], "pa", 2) ? push_ab(root_a, root_a) : 0;
    !ft_strncmp_end(rules[*i], "pb", 2) ? push_ab(root_b, root_a) : 0;
}

static void check_swap(t_stack **root_a, t_stack **root_b, char **rules, int *i)
{
    !ft_strncmp_end(rules[*i], "sa", 2) ? swap(root_a) : 0;
    !ft_strncmp_end(rules[*i], "sb", 2) ? swap(root_b) : 0;
    if (!(ft_strncmp_end(rules[*i], "ss", 2)))
    {
        swap(root_a);
        swap(root_b);
    }
}

void    execute_rules(t_stack **root_a, t_stack **root_b, char **rules)
{
    int i = 0;
    while (rules[i])
    {
        check_swap(root_a, root_b, rules, &i);
        check_push(root_a, root_b, rules, &i);
        check_rotate(root_a, root_b, rules, &i);
        check_rr(root_a, root_b, rules, &i);
        free(rules[i]);
        i++;
    }
}