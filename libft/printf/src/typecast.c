/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typecast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:12:41 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/03 17:49:04 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	typecast_f(va_list args, t_info *info)
{
	if (info->length == 'g')
		info->output_f = (long double)va_arg(args, long double);
	else
		info->output_f = (double)va_arg(args, double);
}

void	typecast_int(va_list args, t_info *info)
{
	if (info->length == 'g')
		info->output = (long)va_arg(args, void*);
	else if (info->length == 'G')
		info->output = (long long)va_arg(args, void*);
	else if (info->length == 'h')
		info->output = (short)va_arg(args, void*);
	else if (info->length == 'H')
		info->output = (char)va_arg(args, void*);
	else
		info->output = va_arg(args, int);
}

void	typecast_u(va_list args, t_info *info)
{
	if (info->length == 'g')
		info->output_u = (unsigned long)va_arg(args, void*);
	else if (info->length == 'G')
		info->output_u = (unsigned long long)va_arg(args, void*);
	else if (info->length == 'h')
		info->output_u = (unsigned short)va_arg(args, void*);
	else if (info->length == 'H')
		info->output_u = (unsigned char)va_arg(args, void*);
	else
		info->output_u = va_arg(args, unsigned int);
}
