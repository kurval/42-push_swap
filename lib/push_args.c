/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:38:48 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/28 17:18:14 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void		push_args(int arg, char **argc, t_stack **root_a)
{
    while (--arg)
		push(root_a, ft_atoi(argc[arg]), 'a', 0);
}