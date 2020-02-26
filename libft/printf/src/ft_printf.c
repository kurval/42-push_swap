/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:56:55 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/06 08:27:24 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	init_info(t_info *info)
{
	info->len = 0;
	info->plus = 0;
	info->minus = 0;
	info->hash = 0;
	info->space = 0;
	info->zero = 0;
	info->nb = 0;
	info->width = 0;
	info->length = 0;
	info->precision = 0;
	info->nbr = 0;
	info->sign = 0;
	info->output = 0;
	info->output_f = 0;
	info->output_u = 0;
	info->dot = 0;
}

int		ft_printf(const char *format, ...)
{
	va_list args;
	int		bytes;
	t_info	info;

	bytes = 0;
	info.i = -1;
	info.bytes = &bytes;
	va_start(args, format);
	while (format[++info.i] != '\0')
	{
		init_info(&info);
		(format[info.i] == '%') ? parser(&info, format, args) :\
		ft_putcharb(format[info.i], info.bytes);
		if (format[info.i] == '\0')
			return (0);
	}
	va_end(args);
	return (*info.bytes);
}
