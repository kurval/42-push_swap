/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:04:40 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/03 10:38:50 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void	flag_uint2(t_info *info)
{
	info->width && info->zero && !info->precision ?\
	put_zeros(info->width, &info->len, info->bytes) : 0;
	info->precision || info->zero ?\
	put_zeros(info->precision, &info->len, info->bytes) : 0;
	if (info->minus)
	{
		!(info->nb && info->output_u == 0) ?\
		ft_putnbrb(info->output_u, info->bytes) : 0;
		put_spaces(info->width, info->len, info->bytes);
		return ;
	}
	if (info->nb && info->output_u == 0)
		return ;
	ft_putnbru(info->output_u, info->bytes);
}

void		flag_uint(va_list args, t_info *info)
{
	typecast_u(args, info);
	info->len = ft_numlenu(info->output_u);
	(info->nb == -1 || info->nb == -2) &&\
	info->output_u == 0 ? info->len = 0 : 0;
	info->width && !info->zero && !info->minus && !info->precision ?\
	put_spaces(info->width, info->len, info->bytes) : 0;
	if (info->width && info->precision && !info->minus)
	{
		if (info->width > info->precision && info->precision > info->len)
			(info->plus || info->space) ?\
			put_spaces(info->width, info->precision + 1, info->bytes) :\
			put_spaces(info->width, info->precision, info->bytes);
		else if (info->width > info->precision && info->width > info->len)
			put_spaces(info->width, info->len, info->bytes);
	}
	flag_uint2(info);
}
