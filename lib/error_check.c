/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:17:57 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/28 17:52:26 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int	cmp(int value1, int value2)
{
	if (value1 == value2)
		return (0);
	else
		return (1);
}

void		error_check(int arg, char **argc, int s)
{
	int i;

	if (arg == 1)
		exit(0);
	i = (check_flag(argc[1])) ? 1 : 0;
	while (--arg > i)
	{
		if (ft_atoi_err(argc[arg]) == -1)
		{
			ft_printf(BOLDRED "Error\n" RESET);
			(s) ? free_tab(argc) : 0;
			exit(0);
		}
	}
}

void		error_doubles(t_stack *lst)
{
	t_stack	*future;

	while (lst)
	{
		future = lst->next;
		while (future)
		{
			if (!cmp(lst->data, future->data))
			{
				ft_printf(BOLDRED "Error\n" RESET);
				free_stack(lst);
				exit(0);
			}
			future = future->next;
		}
		lst = lst->next;
	}
}
