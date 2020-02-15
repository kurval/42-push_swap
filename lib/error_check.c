/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:17:57 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/15 11:30:46 by vkurkela         ###   ########.fr       */
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

void		error_check(int arg, char **argc)
{
	if (arg == 1)
	{
		ft_printf(BOLDRED "Error\n" RESET);
		exit(0);
	}
	while (--arg > 0)
	{
		if (ft_atoi(argc[arg]) == -1)
		{
			ft_printf(BOLDRED "Error\n" RESET);
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
				exit(0);
			}
			future = future->next;
		}
		lst = lst->next;
	}
}
