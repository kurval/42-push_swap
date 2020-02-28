/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:38:48 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/28 20:31:20 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void		push_args(int arg, char **argc, t_stack **root_a, char stack)
{
    while (--arg > check_flag(argc[1]))
		  push(root_a, ft_atoi(argc[arg]), stack, check_flag(argc[1]));
}