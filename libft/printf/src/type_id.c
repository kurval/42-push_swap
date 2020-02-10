/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 12:57:25 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/03 10:38:24 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void	flag_int4(t_info *info)
{
	if (info->minus)
	{
		if (info->output < 0)
		{
			ft_putcharb('-', info->bytes);
			info->output *= -1;
		}
		!(info->nb && info->output == 0) ?\
		ft_putnbrb(info->output, info->bytes) : 0;
		(info->output >= 0 && (info->plus || info->space) &&\
		!(info->precision < info->len) && !info->sign) ? info->len += 1 : 0;
		info->sign == 1 && !(info->precision < info->len) ? info->len += 1 : 0;
		put_spaces(info->width, info->len, info->bytes);
		return ;
	}
	if (info->nb && info->output == 0)
		return ;
	ft_putnbrb(info->output, info->bytes);
}

static void	flag_int3(t_info *info)
{
	info->space && !info->minus && info->width &&\
	!info->zero && !info->precision ?\
	put_spaces(info->width, info->len, info->bytes) : 0;
	if (info->output >= 0 && (info->plus || info->space))
		info->plus ? put_plus(info->bytes) : put_space(info->bytes);
	if (info->precision || info->zero)
	{
		if (info->output < 0)
		{
			ft_putcharb('-', info->bytes);
			info->output *= -1;
			info->sign = 1;
		}
		info->precision ?\
		put_zeros(info->precision, &info->len, info->bytes) : 0;
		info->zero && !info->precision && !info->minus ?\
		put_zeros(info->width, &info->len, info->bytes) : 0;
	}
	flag_int4(info);
}

static void	flag_int2(t_info *info)
{
	info->width && !info->zero && !info->space && !info->minus &&\
	!info->precision ? put_spaces(info->width, info->len, info->bytes) : 0;
	if (info->width && info->precision && !info->minus)
	{
		if (info->width > info->precision && info->precision > info->len)
			(info->plus || info->space || info->output < 0) ?\
			put_spaces(info->width, info->precision + 1, info->bytes) :\
			put_spaces(info->width, info->precision, info->bytes);
		else if (info->width > info->precision && info->width > info->len)
			put_spaces(info->width, info->len, info->bytes);
	}
	flag_int3(info);
}

void		flag_int(va_list args, t_info *info)
{
	typecast_int(args, info);
	info->len = ft_numlen(info->output);
	info->len = (info->output >= 0 && (info->plus || info->space) &&\
	info->precision < info->width &&\
	info->precision <= info->len) ? info->len + 1 : info->len;
	info->len = (info->precision >= info->len && info->output < 0) ?\
	info->len - 1 : info->len;
	info->nb && info->output == 0 ? info->len = 0 : 0;
	info->nb && info->output == 0 && (info->plus || info->space) ?\
	info->len = 1 : 0;
	flag_int2(info);
}
