/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_med.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:20:57 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/20 17:03:10 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int sort_list(int *tab, unsigned int size)
{
	int				tmp;
	unsigned int 	i;
	unsigned int 	j;
	int				med;

	i = 0;
	while (i < size - 1)
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j += 1;
		}
		i += 1;
	}
	med = tab[size/2];
	return (med);
}

int	calc_med(t_stack *root_a, int size)
{
    t_stack *current;
	int		*tab;
	int		i;
	int		med;

	current = root_a;
	med = 0;
	i = 0;
	if (!(tab = (int*)malloc(sizeof(int) * size + 1)))
		return (0);
	while (current)
	{
		tab[i] = current->data;
		current = current->next;
		i++;
	}
	med = sort_list(tab, size);
	free(tab);
    return (med);
}