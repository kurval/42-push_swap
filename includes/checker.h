/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 10:25:12 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/19 12:41:28 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define MAX 10000

# include "../libft/libft.h"
# include "../lib/lib.h"

int		main(int arg, char **argc);
int		read_instructions(char **rules);
void	push_ab(t_stack **root, t_stack **stack);
void	swap(t_stack **root);
void	reverse_rotate(t_stack **root);
void	rotate(t_stack **root);
void	execute_rules(t_stack **root_a, t_stack **root_b, char **rules);
int		check_rules(char **rules);

#endif
