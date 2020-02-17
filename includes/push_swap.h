/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:11:14 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/17 15:29:13 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../lib/lib.h"

int						main(int arg, char **argc);
void					sort_stack(t_stack **root_a, t_stack **root_b);
void					sort_stack_3(t_stack **root_a);
void	                sort_stack_test(t_stack **root_a, t_stack **root_b);
void                    quick_sort(t_stack **root_a, t_stack **root_b, int size);
void                    sort_five(t_stack **root_a, t_stack **root_b, int lo, int size);

#endif
