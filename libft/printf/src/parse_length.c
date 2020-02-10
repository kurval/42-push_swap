/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:44:10 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/03 18:10:24 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	parse_ll(va_list args, const char *str, t_info *info)
{
	info->i += 2;
	info->flag = str[info->i];
	if (info->flag == 'd' || info->flag == 'i')
	{
		info->length = 'G';
		flag_int(args, info);
	}
	else if (info->flag == 'u')
	{
		info->length = 'G';
		flag_uint(args, info);
	}
	else if (info->flag == 'o')
	{
		info->length = 'G';
		flag_oct(args, info, info->flag);
	}
	else if (info->flag == 'x' || info->flag == 'X')
	{
		info->length = 'G';
		flag_hex(args, info, info->flag);
	}
	else
		info->i -= 2;
}

void	parse_l(va_list args, const char *str, t_info *info)
{
	info->i += 1;
	info->flag = str[info->i];
	if (info->flag == 'd' || info->flag == 'i')
	{
		info->length = 'g';
		flag_int(args, info);
	}
	else if (info->flag == 'u')
	{
		info->length = 'g';
		flag_uint(args, info);
	}
	else if (info->flag == 'o')
	{
		info->length = 'g';
		flag_oct(args, info, info->flag);
	}
	else if (info->flag == 'x' || info->flag == 'X')
	{
		info->length = 'g';
		flag_hex(args, info, info->flag);
	}
	else
		info->i -= 1;
}

void	parse_h(va_list args, const char *str, t_info *info)
{
	info->i += 1;
	info->flag = str[info->i];
	if (info->flag == 'd' || info->flag == 'i')
	{
		info->length = 'h';
		flag_int(args, info);
	}
	else if (info->flag == 'u')
	{
		info->length = 'h';
		flag_uint(args, info);
	}
	else if (info->flag == 'o')
	{
		info->length = 'h';
		flag_oct(args, info, info->flag);
	}
	else if (info->flag == 'x' || info->flag == 'X')
	{
		info->length = 'h';
		flag_hex(args, info, info->flag);
	}
	else
		info->i -= 1;
}

void	parse_hh(va_list args, const char *str, t_info *info)
{
	info->i += 2;
	info->flag = str[info->i];
	if (info->flag == 'd' || info->flag == 'i')
	{
		info->length = 'H';
		flag_int(args, info);
	}
	else if (info->flag == 'u')
	{
		info->length = 'H';
		flag_uint(args, info);
	}
	else if (info->flag == 'o')
	{
		info->length = 'H';
		flag_oct(args, info, info->flag);
	}
	else if (info->flag == 'x' || info->flag == 'X')
	{
		info->length = 'H';
		flag_hex(args, info, info->flag);
	}
	else
		info->i -= 2;
}

void	parse_f(va_list args, const char *str, t_info *info)
{
	info->i += 1;
	info->flag = str[info->i];
	if (str[info->i - 1] == 'l')
		flag_float(args, info);
	else if (info->flag == 'f')
	{
		info->length = 'g';
		flag_float(args, info);
	}
	else
		info->i -= 1;
}
