/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:04:11 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/01 13:55:54 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void	flag_str2(t_info *info, char *output)
{
	info->width && !info->minus ?\
		put_spaces(info->width, info->len, info->bytes) : 0;
	if (info->minus)
	{
		!(info->nb && info->output == 0) ?\
		ft_putstrb(output, info->bytes) : 0;
		put_spaces(info->width, info->len, info->bytes);
		info->precision ? free(output) : 0;
		return ;
	}
	if (info->nb)
		return ;
	ft_putstrb(output, info->bytes);
	info->precision ? free(output) : 0;
}

void		flag_str(va_list args, t_info *info)
{
	char *output;

	output = va_arg(args, char*);
	output == NULL ? output = "(null)" : 0;
	info->len = !(info->nb) ? ft_strlen(output) : 0;
	if (info->precision)
	{
		output = ft_strsub(output, 0, info->precision);
		info->len = ft_strlen(output);
	}
	flag_str2(info, output);
}
