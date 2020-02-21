/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_med.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:20:57 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/21 10:55:30 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void sort_list(int *tab, unsigned int size, int *med)
{
	unsigned int 	i;
	unsigned int 	j;

	i = 0;
	while (i < size - 1)
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j += 1;
		}
		i += 1;
	}
	if (size % 2 != 0)
		*med = tab[size/2];
	else
		*med = ((tab[(size/2) - 1] + tab[(size/2)]) / 2);
}

int	*calc_med(t_stack *root_a, int size, int *med)
{
    t_stack *current;
	int		*tab;
	int		i;

	current = root_a;
	i = 0;
	if (!(tab = (int*)malloc(sizeof(int) * size + 1)))
		return (0);
	while (current)
	{
		tab[i] = current->data;
		current = current->next;
		i++;
	}
	sort_list(tab, size, med);
    return (tab);
}