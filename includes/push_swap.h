/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:11:14 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/11 19:15:33 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct          s_stack
{
	int                 data;
	struct s_stack    	*next;
}                       t_stack;

int                     main(int arg, char **argc);
void					error_check(int arg, char **argc);
void					error_doubles(t_stack *lst);
t_stack					*new_node(int data);
void					push(t_stack **root, int data);
void 					push_b(t_stack **root_a, t_stack **root_b);
void					push_a(t_stack **root_b, t_stack **root_a);
int						isEmpty(t_stack *root);
void					swap_a(t_stack **root_a);
void					swap_b(t_stack **root_b);
void					rotate_a(t_stack **root_a);

#endif
