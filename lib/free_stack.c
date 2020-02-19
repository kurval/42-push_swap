/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:48:25 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/14 10:04:13 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	free_stack(t_stack *root)
{
	t_stack *temp;

	temp = NULL;
	if (is_empty(root))
		return ;
	while (root)
	{
		temp = root;
		root = root->next;
		free(temp);
	}
}
