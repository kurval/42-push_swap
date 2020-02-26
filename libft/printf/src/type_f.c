/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:58:15 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/09 17:50:52 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void	flag_float4(t_info *info)
{
	if (info->zero)
	{
		if (info->sign)
		{
			ft_putcharb('-', info->bytes);
			info->sign = 0;
		}
		info->zero ? put_zeros(info->width, &info->len, info->bytes) : 0;
	}
	info->sign && info->nbr[0] != '-' ? ft_putcharb('-', info->bytes) : 0;
	ft_putstrb(info->nbr, info->bytes);
	free(info->nbr);
}

static void	flag_float3(t_info *info)
{
	info->width && !info->zero && !info->space &&\
	!info->minus ? put_spaces(info->width, info->len, info->bytes) : 0;
	if (info->output_f >= 0 && (info->plus || info->space))
		info->plus ? put_plus(info->bytes) : put_space(info->bytes);
	info->space && info->width && !info->zero && !info->minus ?\
		put_spaces(info->width, info->len, info->bytes) : 0;
	if (info->minus)
	{
		if (info->sign)
		{
			ft_putcharb('-', info->bytes);
			info->sign = 0;
		}
		ft_putstrb(info->nbr, info->bytes);
		put_spaces(info->width, info->len, info->bytes);
		free(info->nbr);
		return ;
	}
	flag_float4(info);
}

static void	flag_float2(t_info *info)
{
	info->len = ft_strlen(info->nbr);
	info->output_f < 0 ? info->len += 1 : 0;
	info->len = (info->output_f >= 0 && (info->plus || info->space)) ?\
	info->len + 1 : info->len;
	info->nb && info->output_f == 0 ? info->len = 0 : 0;
	info->nb && info->output_f == 0 && (info->plus || info->space) ?\
	info->len = 1 : 0;
	flag_float3(info);
}

void		flag_float(va_list args, t_info *info)
{
	int	round;

	round = info->precision;
	typecast_f(args, info);
	(info->precision >= 1) ? info->dot = 1 : 0;
	info->sign = (info->output_f < 0) ? 1 : 0;
	if (info->precision == 0 && !info->nb)
	{
		round = 6;
		info->dot = 1;
	}
	else if (info->hash && info->nb
		&& !info->dot && info->output_f != 0)
	{
		info->dot = 1;
		round = 0;
	}
	info->nbr = ft_ftoa(info->output_f, round, info->dot);
	flag_float2(info);
}
