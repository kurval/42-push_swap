/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:33:12 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/03 17:52:43 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void	flag_hex4(t_info *info, char flag)
{
	(info->precision || info->zero) ?\
	put_zeros(info->precision, &info->len, info->bytes) : 0;
	if (info->minus)
	{
		!(info->nb && info->output_u == 0) ?\
		ft_itoa_baseb(info->output_u, 16, info->bytes, flag) : 0;
		(info->hash && info->output_u != 0) &&\
		!(info->precision < info->len) ? info->len += 2 : 0;
		put_spaces(info->width, info->len, info->bytes);
		return ;
	}
	if (info->nb && info->output_u == 0)
		return ;
	ft_itoa_baseb(info->output_u, 16, info->bytes, flag);
}

static void	flag_hex3(t_info *info, char flag)
{
	if (info->hash)
	{
		if (info->output_u != 0)
			flag == 'x' ? ft_putstrb("0x", info->bytes) :\
			ft_putstrb("0X", info->bytes);
		if (info->zero && !info->minus)
		{
			info->precision ?\
			put_zeros(info->precision, &info->len, info->bytes) : 0;
			info->zero && !info->precision && !info->minus ?\
			put_zeros(info->width, &info->len, info->bytes) : 0;
		}
	}
	flag_hex4(info, flag);
}

static void	flag_hex2(t_info *info, char flag)
{
	info->width && !info->zero && !info->minus && !info->precision ?\
	put_spaces(info->width, info->len, info->bytes) : 0;
	if (info->width && info->precision && !info->minus)
	{
		if (info->width > info->precision && info->precision > info->len)
			(info->hash && info->output_u != 0) ?\
			put_spaces(info->width, info->precision + 2, info->bytes) :
			put_spaces(info->width, info->precision, info->bytes);
		else if (info->width > info->precision && info->width > info->len)
			put_spaces(info->width, info->len, info->bytes);
	}
	info->width && info->zero && !info->hash && !info->precision ?\
	put_zeros(info->width, &info->len, info->bytes) : 0;
	flag_hex3(info, flag);
}

void		flag_hex(va_list args, t_info *info, char flag)
{
	typecast_u(args, info);
	info->nbr = ft_itoa_base(info->output_u, 16);
	info->len = ft_strlen(info->nbr);
	free(info->nbr);
	info->len = (info->hash && info->output_u != 0 &&\
	info->precision < info->width && info->precision <= info->len) ?\
	info->len + 2 : info->len;
	info->nb && info->output_u == 0 ? info->len = 0 : 0;
	flag_hex2(info, flag);
}
