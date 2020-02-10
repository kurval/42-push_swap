/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:57:38 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/03 18:02:24 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void	flags(t_info *info, const char *str, va_list args)
{
	char flag;

	flag = str[info->i];
	if (flag == '#')
		info->hash = 1;
	else if (flag == '-')
		info->minus = 1;
	else if (flag == ' ')
		info->space = 1;
	else if (flag == '0')
		info->zero = 1;
	else if (flag == '+')
		info->plus = 1;
	parser(info, str, args);
}

static void	parse_flags(t_info *info, const char *str, va_list args)
{
	char flag;

	flag = str[info->i];
	flag > '0' && flag <= '9' ? width(info, str, args) : 0;
	flag == '*' ? width(info, str, args) : 0;
	flag == '.' ? precision(info, str, args) : 0;
	flag == '0' ? flags(info, str, args) : 0;
	flag == '+' ? flags(info, str, args) : 0;
	flag == ' ' ? flags(info, str, args) : 0;
	flag == '#' ? flags(info, str, args) : 0;
	flag == '-' ? flags(info, str, args) : 0;
}

static void	parse_length(t_info *info, const char *str, va_list args)
{
	char flag;

	flag = str[info->i];
	flag == 'h' && str[info->i + 1] != 'h' ? parse_h(args, str, info) : 0;
	flag == 'h' && str[info->i + 1] == 'h' ? parse_hh(args, str, info) : 0;
	flag == 'l' && str[info->i + 1] != 'l' ? parse_l(args, str, info) : 0;
	flag == 'l' && str[info->i + 1] == 'l' ? parse_ll(args, str, info) : 0;
	flag == 'l' && str[info->i + 1] == 'f' ? parse_f(args, str, info) : 0;
	flag == 'L' && str[info->i + 1] == 'f' ? parse_f(args, str, info) : 0;
	parse_flags(info, str, args);
}

void		parser(t_info *info, const char *str, va_list args)
{
	char flag;

	info->i += 1;
	flag = str[info->i];
	flag == 'd' ? flag_int(args, info) : 0;
	flag == 'i' ? flag_int(args, info) : 0;
	flag == 'u' ? flag_uint(args, info) : 0;
	flag == 'o' ? flag_oct(args, info, flag) : 0;
	flag == 'x' ? flag_hex(args, info, flag) : 0;
	flag == 'X' ? flag_hex(args, info, flag) : 0;
	flag == 'b' ? flag_oct(args, info, flag) : 0;
	flag == 'c' ? flag_char(args, info) : 0;
	flag == 's' ? flag_str(args, info) : 0;
	flag == 'p' ? flag_ptr(args, info, flag) : 0;
	flag == 'f' ? flag_float(args, info) : 0;
	flag == '%' ? flag_percent(info) : 0;
	flag == 'a' ? flag_arr(args, info) : 0;
	flag == 'n' ? flag_str_len(args, info) : 0;
	flag == 'N' ? flag_num_len(args, info) : 0;
	parse_length(info, str, args);
}
