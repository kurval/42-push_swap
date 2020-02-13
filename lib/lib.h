/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:11:14 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/13 21:11:47 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "../libft/libft.h"

typedef struct          s_stack
{
	int                 data;
	struct s_stack    	*next;
	char				stack;
}                       t_stack;

void					error_check(int arg, char **argc);
void					error_doubles(t_stack *lst);
t_stack					*new_node(int data);
void					del_node(t_stack **node);
void					push(t_stack **root, int data);
int						is_empty(t_stack *root);
void					print_stack(t_stack *root);
void					free_stack(t_stack *root);

#endif
