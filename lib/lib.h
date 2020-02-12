/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:51:31 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/12 17:05:11 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "../includes/push_swap.h"

void					error_check(int arg, char **argc);
void					error_doubles(t_stack *lst);
t_stack					*new_node(int data);
void					del_node(t_stack **node);
void					push(t_stack **root, int data);
int						is_empty(t_stack *root);

#endif