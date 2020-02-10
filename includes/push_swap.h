/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:11:14 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/10 15:26:56 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct          s_stack_a
{
	int                 data;
	struct s_stack_a    *next;
}                       t_stack_a;

int                     main(int arg, char **argc);
void					error_check(int arg, char **argc);
void					error_doubles(t_stack_a *lst);
t_stack_a*				newNode(int data);
void					push(t_stack_a **root, int data);

#endif
