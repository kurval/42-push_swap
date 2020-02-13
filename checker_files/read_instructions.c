/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 10:56:37 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/13 11:11:03 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	add_to_rules(char **rules, char *rule, int *nbr)
{
	rules[*nbr] = rule;
}

int	read_instructions(char **rules)
{
    int     ret;
	char    *buff;
	char    *str;
	int		nbr;

	nbr = 0;
	if (!(str = ft_strnew(1)))
		return (0);
    while ((ret = get_next_line(0, &buff)) > 0)
    {
		if (!(str = ft_strdup(buff)))
			return (0);
		add_to_rules(rules, str, &nbr);
		nbr++;
        free(buff);
    }
	rules[nbr] = NULL;
	if (ret == -1)
		ft_printf(0);
    return (1);
}