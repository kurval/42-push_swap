/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:11:14 by vkurkela          #+#    #+#             */
/*   Updated: 2020/03/02 11:36:44 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# define RESET   "\033[0m"
# define BLACK   "\033[30m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"
# define BOLDBLACK   "\033[1m\033[30m"
# define BOLDRED     "\033[1m\033[31m"
# define BOLDGREEN   "\033[1m\033[32m"
# define BOLDYELLOW  "\033[1m\033[33m"
# define BOLDBLUE    "\033[1m\033[34m"
# define BOLDMAGENTA "\033[1m\033[35m"
# define BOLDCYAN    "\033[1m\033[36m"
# define BOLDWHITE   "\033[1m\033[37m"

# include "../libft/libft.h"

typedef struct			s_stack
{
	int					data;
	struct s_stack		*next;
	char				stack;
	int					both;
	int					flag;
}						t_stack;

typedef struct			s_rules
{
	char				data[4];
	struct s_rules		*next;
}						t_rules;

void					error_check(int arg, char **argc, int s);
void					error_doubles(t_stack *lst);
t_stack					*new_node(int data, char c, int sort);
void					del_node(t_stack **node);
void					push(t_stack **root, int data, char c, int sort);
int						is_empty(t_stack *root);
void					print_stack(t_stack *root_a, t_stack *root_b);
void					free_stack(t_stack *root);
void					push_ab(t_stack **root, t_stack **stack);
void					swap(t_stack **root);
void					swap_both(t_stack **root_a, t_stack **root_b);
void					reverse_rotate(t_stack **root);
void					rev_rot_both(t_stack **root_a, t_stack **root_b);
void					rotate(t_stack **root);
void					rotate_both(t_stack **root_a, t_stack **root_b);
int						check_order(t_stack *root_a, t_stack *root_b);
t_rules					*new_rule(char *data);
void					push_rules(t_rules **rules, char *data);
void					free_rules(t_rules *rules);
void					print_rules(t_rules *rules);
int						check_rev_order(t_stack *root_b);
int						*sort_tab(t_stack *root_a, int size);
int						check_flag(char *first);
void					push_args(int arg, char **argc,\
		t_stack **root_a, char stack);
void					free_tab(char **tab);
void					print_start(t_stack *root_a, t_stack *root_b);
void					print_steps(t_stack *root_a,\
		t_stack *root_b, char *step);
int						count_rules(t_rules *rules);
void					print_lines(t_stack *root_a, int size);
#endif
