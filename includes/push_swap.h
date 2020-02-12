/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:11:14 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/12 13:52:56 by vkurkela         ###   ########.fr       */
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
void					push_ab(t_stack **root, t_stack **stack);
int						is_empty(t_stack *root);
void					swap(t_stack **root);
void 					reverse_rotate(t_stack **root);
void					del_node(t_stack **node);
void					rotate(t_stack **root);
void					sort_stack(t_stack **root_a, t_stack **root_b);
void    				sort_stack_3(t_stack **root_a);
void					print_stack(t_stack *root);

#endif
