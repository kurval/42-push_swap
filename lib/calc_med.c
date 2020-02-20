/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_med.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:20:57 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/20 21:35:26 by vkurkela         ###   ########.fr       */
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

static int sort_list(int *tab, unsigned int size)
{
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
				ft_swap(&tab[i], &tab[j]);
			j += 1;
		}
		i += 1;
	}
	if (size % 2 != 0)
		med = tab[size/2];
	else
		med = ((tab[(size/2) - 1] + tab[(size/2)]) / 2);
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