/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:38:48 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/02 11:37:35 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	push_args(int arg, char **argc, t_stack **root_a, char stack)
{
	int flag;

	flag = check_flag(argc[1]);
	while (--arg > flag)
		push(root_a, ft_atoi(argc[arg]), stack, flag);
}
